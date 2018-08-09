#include <stdio.h>
#include <conio.h>
#define MAX 100
int A[MAX];
int top=-1;
void Push(int n);
void Pop();
void Print();
void Print();
int main()
{
    int ans=1;
    int i=0;
    printf("Press 1 to push\nPress 2 to pop\n\n");
    while(1)
    {
        scanf("%d",&ans);
        if(ans==1)
        {
            Push(i);
            Print();
        }
        if(ans==2)
        {
            Pop();
            Print();
        }
        if(ans==3)
        {
            printf("Exiting...");
            break;
        }
        i++;
    }
    
    Push(6);
}
void Print()
{
    int i;
    for(i=0;i<top;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void Push(int n)
{
    if (top>=MAX)
    {
        printf("Error stack overflow");
        return;
    }
    top++;
    A[top]=n;
}

void Pop()
{
    if(top<=0)
    {
        printf("Error list is empty");
        return;
    }
    top--;
}