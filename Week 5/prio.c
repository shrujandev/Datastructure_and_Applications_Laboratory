#include<stdio.h>
#include<stdlib.h>
struct person{
    char name[10];
    int age;
    char cm;
    int pt;
};

struct person read()
{ 
    struct person t;
    printf("Enter name ");
    scanf("%s",t.name);
    fflush(stdin);
    printf("Enter age ");
    scanf("%d",&t.age);
    fflush(stdin);
    printf("Are you comorbid y/n ");
    scanf("%c",&t.cm);
    if(t.age>65)
        t.pt=1;
    else if(t.cm=='y')
        t.pt=2;
    else if(t.age>45)
         t.pt=3;
    else if(t.age>18)
        t.pt=4;
    else
        { printf("Invalid age");
            t.pt=-1;
        }
    return t;
}
void pq_insert(int*count,struct person p[20])
{
    struct person temp;
    temp=read();
    int j;
    j=*count-1;
    while(j>=0&&p[j].pt>temp.pt)
      {
          p[j+1]=p[j];
          j--;
      }
      p[j+1]=temp;
      ++*count;
}

struct person pq_del(struct person p[10],int*count)
{   struct person temp ;
    if(*count==0)
    {
        printf("Queue is empty ");
        
    }
    else{
         temp =p[0];
        for(int i=1;i<*count;i++)
           p[i-1]=p[i];
        --*count;
     
    }
   return temp;   
}

void disp(struct person p[10],int count)
{  if(count==0)
      printf("Queue is empty \n");
    else{
    int i;
    for(i=0;i<count;i++)
    {  
        printf("\nName: %s",p[i].name);
        printf("\nAge: %d",p[i].age);
        printf("\nComorbid:%c ",p[i].cm);
        printf("\nPriority:%d \n",p[i].pt);
        
    }
}
}


void disp1(struct person p)
{
        printf("Deleted element is :\n");
        printf("\nName: %s",p.name);
        printf("\nAge: %d",p.age);
        printf("\nComorbid:%c ",p.cm);
        printf("\nPriority:%d \n",p.pt);
        
    
}

int main()
{ struct person p1[10];
  struct person p2;
  int count=0;
  while(1)
  {     int choice;
        printf("\n1.Add Patient \n");
        printf("2.Dequeue Patient \n");
        printf("3.Display Appointments  \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:pq_insert(&count,p1);
                   disp(p1,count);
                    break;
            case 2:p2=pq_del(p1,&count);
                  disp1(p2);
                   
                   break;
            case 3:disp(p1,count);
                    break;
            case 4:exit(1);
            default: printf("Invalid Choice \n");
                     break;
        } 
  }
}