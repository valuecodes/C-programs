#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
}BstNode;

struct BstNode* Insert(struct BstNode *root,int data);
struct BstNode* getNewNode(int data);
int Search(struct BstNode *root,int data);

int main()
{
    struct BstNode *root;
    root=NULL;
    root=Insert(root,4);
    root=Insert(root,5);
    root=Insert(root,2);
    root=Insert(root,7);
    root=Insert(root,9);
    printf("Write number for search ");
    int num;
    scanf("%d",&num);
    if(Search(root,num)==1)
    {
        printf("Number found");
    }
    else
    {
        printf("Number not found");
    }
}

int Search(struct BstNode *root,int data)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->data==data)
    {
        return 1;
    }
    else if(root->data>=data)
    {
        return Search(root->right,data);
    }
    else
    {
        return Search(root->left,data);
    }

}

struct BstNode* Insert(struct BstNode *root,int data)
{
    struct BstNode *newNode;
    newNode=getNewNode(data);
    if(root==NULL)
    {
        root=newNode;
        return root;
    }
    else if(root->data<=data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
}

struct BstNode* getNewNode(int data)
{
    struct BstNode *newNode;
    newNode=(struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}