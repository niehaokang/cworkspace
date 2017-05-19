/*************************************************************************
	> File Name: graph.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月 5日 21:59:10
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAX 1000

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
    int adjVertexIndex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    VertexType vertexInfo;
    EdgeNode *firstEdge;
}VertexNode, AdjVexList[MAX];

typedef struct
{
    AdjVexList adjList;
    int numVertexes;
    int numEdges;
}GraphAdjList;

int findVertexIndex( GraphAdjList *G, VertexType vt );

void CreateGraph( GraphAdjList *G );

void ShowAdjList( GraphAdjList *G );

void DFS( GraphAdjList *G, int v );

void DFSTraverse( GraphAdjList *G );

void DFSSearch( GraphAdjList *G );

void BFSSearch( GraphAdjList *G );

int visted[MAX];

int main()
{
    GraphAdjList G;
    CreateGraph(&G);
    ShowAdjList(&G);
    memset(visted, 0, sizeof(visted));
    DFSTraverse( &G );
    memset(visted, 0, sizeof(visted));
    DFSSearch( &G );
    memset(visted, 0, sizeof(visted));
    BFSSearch( &G );
    return 0;
}

int findVertexIndex(GraphAdjList *G, VertexType vt )
{
    int i;
    for( i = 0; i < G->numVertexes; i++)
        if( G->adjList[i].vertexInfo == vt)
            return i;
    return -1;
}

void CreateGraph(GraphAdjList *G) //构造图的存储结构（邻接表）
{
    int i, j, k;
    EdgeNode *p;
    VertexType vthead, vttail;
    int weight = 0;
    //printf("please input vertexnums and edgenums:\n");
    scanf("%d %d", &G->numVertexes, &G->numEdges);
    getchar();
    //printf("please input %d vertexes:\n", G->numVertexes);
    for( i = 0; i < G->numVertexes; i++ )
    {
        scanf("%c", &G->adjList[i].vertexInfo);
        G->adjList[i].firstEdge = NULL;
        getchar();
    }
    //printf("please input %d edges info(edgehead edgetail weight):\n", G->numEdges);
    for( k = 0; k < G->numEdges; k++)
    {
        scanf("%c %c %d", &vthead, &vttail, &weight);
        getchar();
        i = findVertexIndex(G, vthead);
        j = findVertexIndex(G, vttail);
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->next = G->adjList[i].firstEdge;
        p->weight = weight;
        p->adjVertexIndex = j;
        G->adjList[i].firstEdge = p;
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->next = G->adjList[j].firstEdge;
        p->weight = weight;
        p->adjVertexIndex = i;
        G->adjList[j].firstEdge = p;
    }
}

void ShowAdjList(GraphAdjList *G)
{
    int i = 0;
    EdgeNode *en;
    while(i < G->numVertexes)
    {
        printf("about vertex %c :", G->adjList[i].vertexInfo);
        if(G->adjList[i].firstEdge != NULL)
        {
            en = G->adjList[i].firstEdge;
            while( en != NULL)
            {

                printf(" <%c, %c, %2d> ", G->adjList[i].vertexInfo, G->adjList[en->adjVertexIndex].vertexInfo, en->weight);
                en = en->next;
            }
        }
        printf("\n");
        i++;
    }
}

void DFS( GraphAdjList *G, int v )
{
    visted[v] = 1;
    printf("%c ", G->adjList[v].vertexInfo);
    EdgeNode *et;
    for(et = G->adjList[v].firstEdge; et != NULL; et = et->next)
    {
        if( !visted[et->adjVertexIndex] )
            DFS(G, et->adjVertexIndex);
    }
}

void DFSTraverse( GraphAdjList *G)//DFS(深度优先遍历)递归实现
{
    int v = 0;
    while( v < G->numVertexes )
    {
        if( !visted[v] )
        {
            DFS( G, v );
        }
        v++;
    }
    printf("\n");
}

void DFSSearch( GraphAdjList *G )//DFS(深度优先遍历)非递归实现
{
    int v = 0;
    int stack[MAX];
    int top = 0;
    EdgeNode *en;
    int index;
    while( v < G->numVertexes )
    {
        if( !visted[v] )
        {
            visted[v] = 1;
            printf("%c ", G->adjList[v].vertexInfo);
            stack[top++] = v;
            en = G->adjList[v].firstEdge;
            while(top > 0)
            {
                while(en != NULL)
                {
                    index = en->adjVertexIndex;
                    if(visted[index] == 0)
                    {
                        visted[index] = 1;
                        printf("%c ", G->adjList[index].vertexInfo);
                        stack[top++] = index;
                        en = G->adjList[index].firstEdge;
                    }
                    else
                        en = en->next;
                }
                en = G->adjList[stack[--top]].firstEdge;
            }
        }
        v++;
    }
    printf("\n");
}

void BFSSearch( GraphAdjList *G )//BFS(广度优先遍历)
{
    int v = 0;
    int index;
    int queue[MAX];
    int head, tail, count;
    head = 0;
    tail = 0;
    count = 0;
    EdgeNode *en;
    while( v < G->numVertexes )
    {
        if(!visted[v])
        {
            visted[v] = 1;
            printf("%c ", G->adjList[v].vertexInfo);
            en = G->adjList[v].firstEdge;
            while( en != NULL )
            {
                queue[tail] = en->adjVertexIndex;
                tail = (tail + 1) % MAX;
                count++;
                en = en->next;
            }
            while(count != 0)
            {
                index = queue[head];
                head = (head + 1) % MAX;
                count--;
                if( !visted[index] )
                {
                    visted[index] = 1;
                    printf("%c ", G->adjList[index].vertexInfo);
                }
                en = G->adjList[index].firstEdge;
                while( en != NULL )
                {
                    if(!visted[en->adjVertexIndex])
                    {
                        queue[tail] = en->adjVertexIndex;
                        tail = (tail + 1) % MAX;
                        count++;
                    }
                    en = en->next;
                }
            }
        }
        v++;
    }
}
