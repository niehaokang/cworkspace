/*************************************************************************
	> File Name: legendary_items.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月14日 星期五 14时46分22秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<math.h>
#define little 0.0000000001
struct bTreeNode
{
    struct bTreeNode * lchild;
    struct bTreeNode * rchild;
    double pp;
    int p;
    int i;
    int l;
    int is_ritht_child;
};

struct bTreeNode * createTree(int n, int p, int q);
struct bTreeNode * createTree_stack(int n, int p, int q);

int main()
{
    int N, P, Q;
    scanf("%d %d %d", &P, &Q, &N);
    struct bTreeNode * btn;
    btn = createTree(N, P, Q);
    return 0;
}

struct bTreeNode * createTree(int n, int p, int q)
{
    struct bTreeNode * queue[1000000];
    int head = 0, tail = 0;
    double exp = 0;
    struct bTreeNode *H, *s, *temp;
    s = ( struct bTreeNode * )malloc(sizeof(struct bTreeNode));
    s->p = 100;
    s->pp = 1.0;
    s->l = 0;
    s->i = 0;
    s->is_ritht_child = 0;
    H = s;
    queue[tail%1000000] = s;
    tail++;
    
    while(head != tail)
    {
        int p_temp = 0;
        temp = queue[head%1000000];
        head++;
        temp->lchild = NULL;
        temp->rchild = NULL;
        if(temp->i >= n || temp->pp < little)
        {
            exp += temp->pp * temp->l;
            continue;
        }
        s = ( struct bTreeNode * )malloc(sizeof(struct bTreeNode));
        temp->lchild = s;
        if(temp->is_ritht_child)
        {
            p_temp = temp->p + q;
            s->p = (p_temp > 100)?100:p_temp;
        }
        else
            s->p = (int)floor(p/(pow(2, temp->i)));
        s->pp = temp->pp * s->p/100.0;
        s->l = temp->l + 1;
        s->i = temp->i + 1;
        s->is_ritht_child = 0;
        queue[tail%1000000] = s;
        tail++;
        if(p_temp >= 100)
            continue;
        s = ( struct bTreeNode * )malloc(sizeof(struct bTreeNode));
        temp->rchild = s;
        s->p = 100 - temp->lchild->p;
        s->pp = temp->pp * s->p/100.0;
        s->l = temp->l + 1;
        s->i = temp->i;
        s->is_ritht_child = 1;
        queue[tail%1000000] = s;
        tail++;
    }
    printf("%.2f\n", exp);
    return H;
}

struct bTreeNode * createTree_stack(int n, int p, int q)
{
}
