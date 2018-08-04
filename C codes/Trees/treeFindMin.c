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
int findMin(struct BstNode *root);

int main()
{
    struct BstNode *root;
    root=NULL;
    root=Insert(root,5);
    root=Insert(root,45);
    root=Insert(root,15);
    root=Insert(root,1);
    root=Insert(root,11);
    root=Insert(root,8);
    root=Insert(root,7);
    root=Insert(root,4);
    root=Insert(root,2);
    root=Insert(root,9);
    int ans;
    ans=findMin(root);
    printf("Min value at tree is %d",ans);
}

int findMin(struct BstNode *root)
{
    if(root==NULL)
    {
        printf("Tree is empty");
        return 0;
    }
    else if(root->left==NULL)
    {
        return root->data;
    }
    return findMin(root->left);
}

struct BstNode* Insert(struct BstNode *root,int data)
{
    struct BstNode *NewNode;
    NewNode=getNewNode(data);
    if(root==NULL)
    {
        root=NewNode;
        return root;
    }
    else if(root->data <= data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
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