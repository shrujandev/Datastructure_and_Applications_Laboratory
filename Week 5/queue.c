#include<stdio.h>
#include<stdlib.h>

int insert(int *q,int *f,int *r,int size,int x);
int delete(int *q,int *f,int *r,int size);
void display(int *q,int f,int r,int size);

int main()
{
    int *q;
    int f,r,size,ch,x,k;

    f=-1;
    r=-1;

    printf("Enter the size of Queue\n");
    scanf("%d",&size);
    q=(int*)malloc(size*(sizeof(int)));

    while(1)
    {
        display(q,f,r,size);
        printf("\n1.Insert Element\n2.Delete Element\n3.Exit\nEnter your choice : ");

        scanf("%d",&ch);

        switch(ch){
            case 1 : printf("\nEnter the Value to be inserted\n");
                    scanf("%d",&x);
                    k = insert(q,&f,&r,size,x);
                    break;
            case 2:k= delete(q,&f,&r,size);
                    break;
            case 3 : exit(0);

        }
    }
} 

int insert(int *q,int *f,int *r,int size,int x)
{
    if(*r==size-1)
    {
        printf("\nQueue Is FULL\n");
        return -1;
    }
    (*r)++;
    q[*r]=x;

    if(*f==-1)
    {
        *f=0;
    }
    return 1;
}

int delete(int *q,int *f,int *r,int size)
{
    int x;
    if(*f==-1)
    {
        printf("\nQueue is Empty\n");
        return -1;

    }

    x=q[*f];
    

    if(*r==*f)
    {
        *r=*f=-1;
    }
    else (*f)++;

    return x;
}


void display(int *q,int f,int r,int size)
{
    if(f==-1)
        printf("\nQueue is Empty\n");
    else
    {
        for(int i=f;i<=r;i++)
        {
            printf("%d - ",q[i]);
        }
    }
}