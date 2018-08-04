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
    int V;
    struct AdjList *array;
}Graph;

struct Graph* createGraph(int V);
void addEdge(struct Graph *graph,int src,int dest);
struct AdjListNode* GetNewNode(int dest);
void printGraph(struct Graph *graph);
int main()
{
    int V=5;
    struct Graph *graph=createGraph(V);
    addEdge(graph,0,1);
    addEdge(graph,2,4);
    addEdge(graph,1,2);
    addEdge(graph,0,4);
    addEdge(graph,3,4);
    printGraph(graph);
}

void printGraph(struct Graph *graph)
{
    int i;
    for(i=0;i<graph->V;i++)
    {
        printf("Node %d connections\nHead",i);
        struct AdjListNode *pCrawl;
        pCrawl=graph->array[i].head;
        while(pCrawl)
        {
            printf("-> %d",pCrawl->dest);
            pCrawl=pCrawl->next;
        }printf("\n");
    }
}

void addEdge(struct Graph *graph,int src,int dest)
{
    struct AdjListNode *newNode;
    newNode=GetNewNode(dest);
    newNode->next=graph->array[src].head;
    graph->array[src].head=newNode;
    newNode=GetNewNode(src);
    newNode->next=graph->array[dest].head;
    graph->array[dest].head=newNode;
}

struct AdjListNode* GetNewNode(int dest)
{
    struct AdjListNode *newNode;
    newNode=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct Graph *graph;
    graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->array=(struct AdjList*)malloc(V*sizeof(struct AdjList));
    int i;
    for(i=0;i<V;i++)
    {
        graph->array[i].head=NULL;
    }
    return graph;
}
