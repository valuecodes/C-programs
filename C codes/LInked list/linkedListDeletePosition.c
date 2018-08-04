#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}Node;

struct Node *head;
void Insert(int n);
void Print();
void deletePosition(int pos);
int main()
{
    head=NULL;
    int len;
    printf("How many numbers you want: ");
    scanf("%d",&len);
    int i,n;
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    int pos;
    for(i=0;i<len;i++)
    {
        printf("Write a position you want to delete");
        scanf("%d",&pos);
        deletePosition(pos);
        Print();
    }
    Print();
}

void deletePosition(int pos)
{
    struct Node* temp1;
    temp1=head;
    int i;
    if(pos==1)
    {
        head=temp1->next;
        free(temp1);
        return;
    }
    for(i=0;i<pos-2;i++)
    {
        temp1=temp1->next;
    }
    struct Node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);

}

void Print()
{
    struct Node* temp;
    temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void Insert(int n)
{
    struct Node* temp1;
    struct Node* temp2;
    temp1=(struct Node*)malloc(sizeof(struct Node));
    temp1->data=n;
    temp1->next=NULL;
    if(head==NULL)
    {
        head=temp1;
        return;
    }
    temp2=head;
    while(temp2->next != NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}