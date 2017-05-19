/*************************************************************************
	> File Name: legendary_items.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月14日 星期五 14时46分22秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<math.h>
struct bTreeNode
{
    struct bTreeNode * lchild;
    struct bTreeNode * rchild;
    struct bTreeNode * parent;
    double pp;
    int p;
    int i;
    int l;
    int is_ritht_child;
};

struct bTreeNode * createTree(int n, int p, int q);
double expected( int p, double pp, int i, int level, int obtain );
void level_search(struct bTreeNode * root);


int N, P, Q;
int little;

int main()
{
    scanf("%d %d %d", &P, &Q, &N);
    little = 0.001/N;
    struct bTreeNode * btn;
    printf("%.2f\n",expected( 100, 1, 0, 0, 1 ));
    //btn = createTree(N, P, Q);
    //level_search(btn);
    //printf("%.2f", expected(btn));
    return 0;
}

struct bTreeNode * createTree(int n, int p, int q)
{
    struct bTreeNode * queue[1000000];
    int head = 0, tail = 0;
    double exp = 0;
    struct bTreeNode *H, *s, *temp;
    s = ( struct bTreeNode * )malloc(sizeof(struct bTreeNode));
    s->parent = NULL;
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
        if(temp->i >= n)
        {
            exp += temp->pp * temp->l;
            continue;
        }
        s = ( struct bTreeNode * )malloc(sizeof(struct bTreeNode));
        s->parent = temp;
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
        s->parent = temp;
        temp->rchild = s;
        s->p = 100 - temp->lchild->p;
        s->pp = temp->pp * s->p/100.0;
        s->l = s->parent->l + 1;
        s->i = s->parent->i;
        s->is_ritht_child = 1;
        queue[tail%1000000] = s;
        tail++;
    }
    printf("%.2f\n", exp);
    return H;
}

void level_search(struct bTreeNode * root)
{
    struct bTreeNode * queue[1000000];
    int head = 0, tail = 0;
    struct bTreeNode *s, *p;
    s = root;
    queue[tail++] = s;
    while( head != tail )
    {
        s = queue[head++];
        printf("%d %d %d %d %.2f\n", s->p, s->l, s->i, s->is_ritht_child, s->pp);
        if(s->lchild != NULL)
            queue[tail++] = s->lchild;
        if(s->rchild != NULL)
            queue[tail++] = s->rchild;
    }
}

double expected(int p, double pp, int i, int level, int obtain )
{
    double exp = 0.0;
    double pp_temp;
    int p_temp;
    if( i >= N || pp < little)
    {
        return pp * level;
    }
    if(obtain)
    {
        p_temp = (int)floor(P/pow( 2, i ));
        pp_temp = pp * p_temp/100.0;
        exp += expected( p_temp, pp_temp, i + 1, level + 1, 1 );
    }
    else
    {
        p_temp = p + Q;
        p_temp = (p_temp > 100)?100:p_temp;
        pp_temp = pp * p_temp/100.0;
        exp += expected( p_temp, pp_temp, i + 1, level + 1, 1 );
    }
    if(p_temp >= 100)
        return exp;
    p_temp = 100 - p_temp;
    pp_temp = pp * p_temp/100.0;
    exp += expected( p_temp, pp_temp, i, level + 1, 0 );
    return exp;
}
