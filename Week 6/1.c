#include<stdio.h>
#include<stdlib.h>

void inorder(int *t,int i);
void insert(int *t,int ele);
void search(int *t,int ele,int i);
int main(){
    
    int t[1000];
    int ch,ele;
    for(int i=0;i<1000;i++)
    {
           t[i]=-1;
           
    }
    
    while(1){
        printf("\nEnter your choice\n1.Insert SRN\n2.Display SRN in Assending order\n3.Search SRN\n0.Exit\nEnter your Choice :");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:printf("\nEnter the SRN : ");
                        scanf("%d",&ele);
                   insert(t,ele);
                   break;
            case 2:printf("\nElements in assending order are\n");
                    inorder (t,0);
                    break;
            case 3:printf("\nEnter the SRN to search :");
                    scanf("%d",&ele);
                    search(t,ele,0);
                    break;
            case 0:exit(0);
        }
    }
    
    

}

void insert(int *t,int ele)
{ 
    int i=0;
    while(t[i]!=-1)
    {
        if(ele<t[i])
        {   
            i=2*i+1;
        }
        else
            i=2*i+2;
    }
    t[i]=ele;
    
    
}

void inorder(int *t,int i)
{
    if(t[i]!=-1)
    {
    inorder(t,2*i+1);
    printf(" %d ",t[i]);
    inorder(t,2*i+2);
    }
}

void search(int *t,int ele,int i)
{
    if(t[i]!=-1)
    {
        search(t,ele,2*i+1);
        if(t[i]==ele)
        {
            printf("\nSRN is present\n");
        }
        search(t,ele,2*i+2);
    }
}

