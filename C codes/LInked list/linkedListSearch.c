#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}Node;

struct Node* Insert(struct Node *head,int n);
void Print(struct Node *head);
void Search(struct Node *head,int a);
int main()
{
    struct Node *head;
    head=NULL;
    int i;
    for(i=0;i<100;i=i+6)
    {
    head=Insert(head,i);
    }
    Print(head);
    int a;
    printf("What number are you looking for");
    scanf("%d",&a);
    Search(head,a);
    // Print(head);
}

void Search(struct Node *head,int a)
{
    struct Node *temp;
    temp=head;
    int cnt=0;
    while(temp != NULL)
    {
        if(temp->data==a)
        {
            printf("Number %d was found at position %d",a,cnt);
            return;
        }
        temp=temp->next;
        cnt++;
    }
    printf("Number %d was not found",a);
    return;
}

void Print(struct Node *head)
{
    printf("List of all numbers: \n");
    struct Node *temp;
    temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
    
}

struct Node* Insert(struct Node *head,int n)
{
    struct Node *temp1;
    struct Node *temp2;
    temp1=(struct Node *)malloc(sizeof(struct Node));
    temp1->data=n;
    temp1->next=NULL;
    if(head==NULL)
    {
        head=temp1;
        return head;
    }
    temp2=head;
    while(temp2->next != NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
    return head;
}