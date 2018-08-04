#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
}AdjListNode;

struct AdjList
{
    struct AdjListNode *head;
}AdjList;

struct Graph
{
    int *visited;
    int V;
    struct AdjList *array;
}Graph;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

struct Graph* createGraph(struct Graph *graph,int V);
void addEdge(struct Graph *graph,int src,int dest);
struct AdjListNode* getNewNode(int dest);
void printGraph(struct Graph *graph);
int visited[20];
void printDepth(struct Graph *graph,int vertex);
void printGraphDepth(struct Graph *graph,int vertex);
void resetVisited(struct Graph *graph);
void printGraphBread(struct Graph *graph,int vertex);
void printBread(struct Graph *graph,struct Node *head,int vertex);
struct Node* Push(struct Node *head,int data);
struct Node* createNewNode(int data);
struct Node *tail;
struct Node* Pop(struct Node *head);

int main()
{
    int V=10;
    struct Graph *graph;
    graph=createGraph(graph,V);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,2,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    addEdge(graph,5,7);
    addEdge(graph,4,5);
    addEdge(graph,2,9);
    addEdge(graph,9,8);
    addEdge(graph,7,2);
    addEdge(graph,6,4);
    addEdge(graph,9,3);
    printGraph(graph);
    printGraphDepth(graph,5);//Depth first traversal starting from 5
    printGraphDepth(graph,0);//Depth first traversal starting from 0
    printGraphBread(graph,0);//Bread first traversal starting from 0
}

void printGraphBread(struct Graph *graph,int vertex)
{
    printf("\n\nPrint breath first\n");
    struct Node *head;
    head=NULL;
    tail=NULL;
    printBread(graph,head,vertex);
    resetVisited(graph);
}

void printBread(struct Graph *graph,struct Node *head,int vertex)
{
    struct AdjListNode *temp=graph->array[vertex].head;
    struct AdjListNode *temp2=graph->array[vertex].head;
    head=Push(head,vertex);
    struct AdjListNode *pCrawl;
    while(head != NULL)
    {   
        vertex=tail->data;
        pCrawl=graph->array[vertex].head;
        if(graph->visited[vertex] == 0)
        {
            printf("Visited %d\n",vertex);
        }
        graph->visited[vertex]=1;
        while(pCrawl)
        {
            int connectedVertex=pCrawl->dest;
            if(graph->visited[connectedVertex]==0)
            {
                head=Push(head,pCrawl->dest);
            }
            pCrawl=pCrawl->next;
        }
        head=Pop(head);
        
    }
}

struct Node* Pop(struct Node *head)
{
    if(head==tail)
    {
        head=NULL;
        return head;
    }
    struct Node *temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
    return head;
}

struct Node* Push(struct Node *head,int data)
{
    struct Node *newNode;
    newNode=createNewNode(data);
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

struct Node* createNewNode(int data)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void printGraphDepth(struct Graph *graph,int vertex)
{
    printf("\n\nPrint depth first\n");
    printDepth(graph,vertex);
    resetVisited(graph);
}

void resetVisited(struct Graph *graph)
{
    int i;
    for(i=0;i<graph->V;i++)
    {
        graph->visited[i]=0;
    }
}

void printDepth(struct Graph *graph,int vertex)
{
    struct AdjListNode *temp=graph->array[vertex].head;
    graph->visited[vertex]=1;
    printf("Visited %d\n",vertex);
    while(temp != NULL)
    {
        int connectedVertex=temp->dest;
        if(graph->visited[connectedVertex]==0)
        {
            printDepth(graph,connectedVertex);
        }
        temp=temp->next;
    }   
}

void printGraph(struct Graph *graph)
{
    int i;
    struct AdjListNode *pCrawl;
    for(i=0;i<graph->V;i++)
    {
        pCrawl=graph->array[i].head;
        printf("Node %d is connected to\nHead",i);
        while(pCrawl)
        {
            printf(" ->%d",pCrawl->dest);
            pCrawl=pCrawl->next;
        }
        printf("\n");
    }
}

struct Graph* createGraph(struct Graph *graph,int V)
{
    graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    int i;
    graph->visited=(int *)malloc(V*(sizeof(int)));
    graph->array=(struct AdjList*)malloc(V*sizeof(struct AdjList));
    for(i=0;i<V;i++)
    {
        graph->visited[i]=0;
        graph->array[i].head=NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph,int src,int dest)
{
    struct AdjListNode *newNode=getNewNode(dest);
    newNode->next=graph->array[src].head;
    graph->array[src].head=newNode;
    newNode=getNewNode(src);
    newNode->next=graph->array[dest].head;
    graph->array[dest].head=newNode;
}

struct AdjListNode* getNewNode(int dest)
{
    struct AdjListNode *newNode;
    newNode=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}