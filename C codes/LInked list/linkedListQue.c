#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
}BstNode;
struct Node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;

struct Node *tail;
struct Node* Push(struct Node *head,struct BstNode *data);
struct Node* getNewNode(struct BstNode *data);
// void Print(struct Node *head);
void Pop();
struct BstNode* Insert(struct BstNode *root,int data);
struct BstNode* GetNewBst(int data);
void findLow(struct BstNode *root);
void printLevel(struct BstNode *root);
void Print(struct Node *temp);
int main()
{
    struct Node *head;
    head=NULL;
    tail=NULL;
    int i;
    struct BstNode *root;
    root=NULL;
    root=Insert(root,7);
    root=Insert(root,3);
    root=Insert(root,9);
    root=Insert(root,2);
    root=Insert(root,8);
    root=Insert(root,1);
    root=Insert(root,15);
    // findLow(root);
    // for(i=0;i<50;i=i+4)
    // {
    //     head=Push(head,i);
    //     if(i>20)
    //     {
    //         Pop();
    //     }  
    //     
    // }
    printLevel(root);
    Print(head);
}

void printLevel(struct BstNode *root)
{
    struct Node *head;
    head=NULL;
    tail=NULL;
    // head=Push(head,root);
        struct BstNode *l=root->left;
        struct BstNode *r=root->right;
        head=Push(head,l);
        head=Push(head,r);
    Print(head);
}
void Print(struct Node *temp)
{
    while(temp != NULL)
    {
        struct BstNode *data;
        data=temp->data;
        printf("%d ",data->data);
        temp=temp->next;
    }
}
void findLow(struct BstNode *root)
{
    while(root->left != NULL)
    {
        root=root->left;
    }
    printf(" low is %d\n",root->data);
}

struct BstNode* Insert(struct BstNode *root,int data)
{
    struct BstNode *newNode;
    newNode=GetNewBst(data);
    if(root==NULL)
    {
        root=newNode;
        return root;
    }
    else if(root->data <= data)
    {
        root->right=Insert(root->right,data);
    }
    else
    {
        root->left=Insert(root->left,data);
    }
    return root;
}

struct BstNode* GetNewBst(int data)
{
    struct BstNode *newNode;
    newNode=(struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void Pop()
{
    struct Node *temp;
    temp=tail;
    struct Node *temp2;
    temp2=temp->prev;
    temp2->next=NULL;
    tail=temp2;
    free(temp);
}
// void Print(struct Node *head)
// {
//     while (head != NULL)
//     {
//         printf("%d ",head->data);
//         head=head->next;
//     }
//     printf("\n");
// }

struct Node* Push(struct Node *head,struct BstNode *data)
{
    struct Node *newNode;
    newNode=getNewNode(data);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return head;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    return head;
}
struct Node* getNewNode(struct BstNode *data)
{
    struct Node* newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

