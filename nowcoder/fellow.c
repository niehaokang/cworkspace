/*************************************************************************
	> File Name: fellow.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月11日 星期四 18时33分26秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define MAX 1000

typedef struct relation 
{
    int adjFellowIndex;
    struct relation *next;
}relation;

typedef struct fellow 
{
    int fellowIndex;
    relation *firstRelation;
}fellow, relationList[MAX];

typedef struct fellowGraph
{
    int fellowNum;
    int relationNum;
    relationList reList;
}fellowGraph;

int visted[MAX];
int cnt[10];
int ct;

void DFS( fellowGraph *G , int v)
{
    visted[v] = 1;
    ct++;
    relation *re;
    for( re = G->reList[v].firstRelation; re != NULL; re = re->next )
    {
        if( !visted[re->adjFellowIndex] )
            DFS(G, re->adjFellowIndex);
    }
}

int count(fellowGraph *G)
{
    memset(visted, 0, sizeof(visted));
    if( !visted[1] )
    {
        DFS(G, 1);
    }
    return ct;
}

int main()
{
    int fellow1, fellow2;
    int i;
    int k = 0;
    fellowGraph G;
    while(scanf("%d %d", &G.fellowNum, &G.relationNum) != EOF)
    {
    if( G.fellowNum == 0 && G.relationNum == 0)
        break;
    memset(G.reList, 0, sizeof(G.reList));
    relation *p;
    for( i = 1; i <= G.fellowNum; i++ )
    {
        G.reList[i].fellowIndex = i;
        G.reList[i].firstRelation = NULL;
    }
    for( i = 0; i < G.relationNum; i++ )
    {
        scanf("%d %d", &fellow1, &fellow2);
        p = (relation *)malloc(sizeof(relation));
        p->next = G.reList[fellow1].firstRelation;
        p->adjFellowIndex = fellow2;
        G.reList[fellow1].firstRelation = p;
        p = (relation *)malloc(sizeof(relation));
        p->next = G.reList[fellow2].firstRelation;
        p->adjFellowIndex = fellow1;
        G.reList[fellow2].firstRelation = p;
    }

    /*
    relation *re;
    i = 0;
    while(i <= G.fellowNum)
    {
        printf("About fellow %d: ", G.reList[i].fellowIndex);
        if( G.reList[i].firstRelation != NULL )
        {
            re = G.reList[i].firstRelation;
            while(re != NULL)
            {
                printf(" < %d, %d > ", G.reList[i].fellowIndex, re->adjFellowIndex);
                re = re->next;
            }
        }
        printf("\n");
        i++;
    }
    */

    ct = -1;
    cnt[k++] = count(&G);
    printf("%d\n", cnt[k-1]);
    }
    printf("\n");
    for( i = 0; i < 10; i++ )
        printf("%d\n", cnt[i]);

    return 0;
}
