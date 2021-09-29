#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    char *name;
    int ph;
    char *add;
    char *area;
    struct node *next,*prev;
}Node;

typedef struct Custname
{
    Node *head;
}CustDetail;

void entry(CustDetail *p);
void display(CustDetail *p);
void sort(CustDetail *p);


int main()
{
    int n;
    CustDetail p;
    

    while (1)
    {
        printf("Enter Your Choice \n1.Enter The Details \n2.Sort\n3.Display\n0.Exit\nYour Choice : ");
        scanf("%d",&n);

    switch(n){
            case 1: entry(&p);
                    printf("\n Entry Successfull\n");
                    break;
            case 2: sort(&p);
                    printf("\nAfter Sort\n");
                    display(&p);
                    break;
            case 3: display(&p);
                    break;
            case 0: exit(0);
    }

    }
    
    
    
}

void entry(CustDetail *p){
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));

    fflush(stdin);

    printf("\nEnter the Customer name\n");
    scanf("%[^\n]%*c",&(temp->name));
    fflush(stdin);
    

    printf("\nEnter the Customer Phone Number\n");
    scanf("%d",&(temp->ph));
    fflush(stdin);
    
    printf("\nEnter the Customer Address\n");
    scanf("%[^\n]%*c",&(temp->add));
    fflush(stdin);

    printf("\nEnter the Customer Area\n");
    scanf("%[^\n]%*c",&(temp->area));
    fflush(stdin);


    temp->next = NULL;
    temp->prev = NULL;

    if(p->head==NULL)
    {
        p->head=temp;
    }
    else{
        p->head->prev=temp;
        temp->next=p->head;
        p->head =temp;
    }
    


    
}

void display(CustDetail *p)
{
    Node *temp;
    temp= (p)->head;

    while(temp->next != NULL)
    {
        printf("\nName : %s\nPhone No: %d\nAddress : %s \nArea : %s\n",(temp->name),(temp->ph),(temp->add),(temp->area));
        temp =temp->next;
    }
}


void sort(CustDetail *p)
{
    Node *temp;
    temp = p->head;
    while(temp->next != NULL)
    {
        if(temp->name > temp->next->name)
        {
            temp->prev->next = temp->next;
            temp->next->prev=temp->prev;
            temp->prev = temp->next;
            temp->next->next=temp;
            temp->next->next->prev = temp;
            temp->next = temp->next->next;
        }
        temp = temp->next;

    }
    
}