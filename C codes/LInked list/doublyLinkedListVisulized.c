#include <stdio.h>
#include <stdlib.h>

//Creates a doubly linked list where you can see the position

struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
void InsertFront(int i);
struct Node* getNode(int i);
void Print();
void Push(int n);
void PrintBackwards();
void Pop();
void movePosition(int n);
void Menu();
struct Node *head;
struct Node *tail;

int main()
{
    head=NULL;
    tail=NULL;
    int i;
    for(i=0;i<60;i=i+4) //Mixes up the data with i+4
    {
        Push(i);
        if(i>25) //Learning how to use Que data structure
        {
            Pop();
        }
        Print();
    }
    PrintBackwards();
    printf("\n\n");
    Menu();
}

void Menu()
{
    struct Node *temp;
    temp=head;
    int pos=3;
    movePosition(pos); //Print current position at the middle
    printf("Press 1 to go backward\nPress 2 to go forward\nPress 3 exit\n");
    int ans=0;
    while(1)
    {
        scanf("%d",&ans);
        if(ans==2)
        {
            if(pos==6)//Doesnt go beyond the end of the list
            {
               movePosition(pos); 
            }
            else
            {
                pos++;
                movePosition(pos);
            }
        }
        if(ans==1)
        {
            if(pos==0)//Doesnt go beyond the start of the list
            {
               movePosition(pos); 
            }
            else
            {
                pos--;
                movePosition(pos);
            }
        }
        if(ans==3)
        {
            return;
        }
    }
}

void movePosition(int n)
{
    struct Node *temp;
    temp=head;
    int pos=0;
    while(temp != NULL)
    {
        if(n==pos)
        {
            printf("|");
        }
        printf("%d",temp->data);
        temp=temp->next;
        if(n==pos)
        {
            printf("|");
        }
        else
        {
            printf(" ");
        }
        pos++;
    }
    printf("\n");
}

void Pop()
{
    struct Node *temp;
    temp=head;
    head=temp->next;
    head->prev=NULL;
    free(temp);
}

void PrintBackwards()
{
    struct Node *temp;
    temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }

}


void Push(int n)
{
    struct Node *newNode=getNode(n);
    struct Node *temp;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    temp=tail;
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}

void Print()
{
    struct Node *temp;
    temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void InsertFront(int i)
{
    struct Node *newNode=getNode(i);
    struct Node *temp;
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

struct Node* getNode(int i)
{
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=i;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}