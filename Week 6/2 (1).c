#include<stdio.h>
#include<stdlib.h>



void preorder(int *t,int i);
void insert(int *t,int ele);
void inorder(int *t,int i,int *f);
void check(int *t,int i);
void check2(int *t,int i);
//void search(int *t,int ele,int i);
int main(){
    
    int t[1000];
    int ch,ele;
    for(int i=0;i<1000;i++)
    {
           t[i]=-1;
           
    }
    
    while(1){
        printf("\nEnter your choice\n1.Insert Elemenrts\n2.Display Elements in Preorder\n3.Check if the tree is binary search tree or Not\n0.Exit\nEnter your Choice :");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:printf("\nEnter the Element : ");
                        scanf("%d",&ele);
                   insert(t,ele);
                   break;
            case 2:printf("\nElements in preorder are\n");
                    preorder(t,0);
                    break;
            case 3:
               
                    check2(t,0);
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
        i++;
    }
    t[i]=ele;
    
}

void preorder(int *t,int i)
{
    if(t[i]!=-1)
    {
    printf(" %d ",t[i]);
    preorder(t,2*i+1);
    
    preorder(t,2*i+2);
    }
}

void check(int *t,int i)
{
    int f=0;
   inorder(t,0,&f);
   if(f==0)
   {
    printf("\n\nThe Tree is Binary search\n\n ");
   }
   else
    printf("\n\nThe tree is not Binary search tree\n\n");
    
}


void inorder(int *t,int i,int *f)
{
    if(t[i]!=-1)
    {
        inorder(t,2*i+1,f);
        if(t[i]>t[i+1])
        {
            *f=1;
        }
   
        inorder(t,2*i+2,f);
   }
}


void check2(int *t,int i)
{
    int f=0;
    while(t[i]!=-1)
    {
        if(t[2*i+1]!=-1)
        {
            if(t[i]>t[2*i+1])
                f=1;
            else 
                f=0;
        }
        if(t[2*i+2]!=-1)
        {
            if(t[i]>t[2*i+2])
                f=1;
            else 
                f=0;
        }
       i++;
        }
       
     if (f==1)
        printf("\n\nBinary Search tree\n\n");
     else
        printf("\n\nBinary tree\n\n");
        
    }

