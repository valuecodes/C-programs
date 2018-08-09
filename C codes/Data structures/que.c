#include <stdio.h>
#define MAX 5
int A[MAX];
int front=0;
int back=0;
void Print();
void Enqueue(int n);
void Dequeue();
int main()
{
    Enqueue(3);
    Print();
    Enqueue(4);
    Print();
    Enqueue(5);
    Print();
    Enqueue(6);
    Print();
    Dequeue();
    Print();
    Dequeue();
    Print();
}
void Dequeue()
{
    back++;
}
void Print()
{
    int i;
    for(i=back;i<front;i++)
    {
        printf("%d",A[i]);
    }
    printf("\n");
}
void Enqueue(int n)
{
    A[front]=n;
    front++;
}