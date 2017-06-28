/*************************************************************************
	> File Name: qsort.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月07日 星期三 09时28分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int a;
    int b;
}node;

int compare( const void *a, const void *b );

int main()
{
    int i;
    node a[20];
    for( i = 0; i < 20; i++ )
    {
        a[i].a = rand() % 20;
        a[i].b = rand() % 20;
    }
    printf("Before sort\n");
    for( i = 0; i < 20; i++ )
        printf("%d %d\n", a[i].a, a[i].b);
    printf("\n");
    qsort( a, 20, sizeof(node), compare );
    //qsort( b, 20, sizeof(int) * 2, compare );
    printf("After sort\n");
    for( i = 0; i < 20; i++ )
        printf("%d %d\n", a[i].a, a[i].b);
    return 0;
}
int compare( const void *a, const void *b )
{
    if(((node *)a)->a == ((node *)b)->a ) 
        return ((node *)a)->b - ((node *)b)->b;
    else
        return ((node *)a)->a - ((node *)b)->a; 
}
