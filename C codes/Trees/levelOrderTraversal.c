#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct BstNode *data;
    struct Node *next;
    struct Node *prev;
}Node;

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
}BstNode;

struct BstNode* Insert(struct BstNode *root,int data);
struct BstNode* getNewBst(int data);
void Print(struct BstNode *root);
void printLevel(struct BstNode *root);
struct Node* Push(struct Node *head,struct BstNode *current);
struct Node* getNewNode(struct BstNode *current);
struct Node* tail;
struct Node* Pop(struct Node *head);

int main()
{
    struct BstNode *root;
    root=NULL;
    root=Insert(root,7);
    root=Insert(root,3);
    root=Insert(root,9);
    root=Insert(root,1);
    root=Insert(root,4);
    root=Insert(root,10);
    Print(root);
    printf("\n\n");
    printLevel(root);
}

void printLevel(struct BstNode *root)
{
    if(root==NULL)
    {
        return;
    }
    struct Node *head;
    head=NULL;
    tail=NULL;
    struct BstNode *current=root;
    head=Push(head,current);
    while(head!=NULL)
    {
        current=tail->data;
        printf("%d ",current->data);
        if(current->left != NULL)
        {
            head=Push(head,current->left);  
        }
        if(current->right != NULL)
        {
            head=Push(head,current->right); 
        }
        head=Pop(head);
    }

}

struct Node* Pop(struct Node *head)
{
    if(head==tail)
    {
        // head->next=NULL;
        // head->prev=NULL;
        head=NULL;
        return head;
    }
    struct Node *temp;
    temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
    return head;
    
}

struct Node* Push(struct Node *head,struct BstNode *current)
{
    struct Node *newNode;
    newNode=getNewNode(current);
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

struct Node* getNewNode(struct BstNode *current)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=current;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void Print(struct BstNode *root)
{
    if(root==NULL)
    {
        return;
    }
    Print(root->left);
    printf("%d ",root->data);
    Print(root->right);
}

struct BstNode* Insert(struct BstNode *root,int data)
{
    struct BstNode *newNode;
    newNode=getNewBst(data);
    if(root==NULL)
    {
        root=newNode;
        return root;
    }
    else if(root->data >= data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
}

struct BstNode* getNewBst(int data)
{
    struct BstNode *newNode;
    newNode=(struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}