/*************************************************************************
	> File Name: qsort.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月07日 星期三 09时28分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int compare( const void * a, const void * b );
int main()
{
    int i;
    int a[20];
    int b[20][2];
    for( i = 0; i < 20; i++ )
    {
        a[i] = (i + 2) * 19 % 20;
        b[i][0] = ( i + 2 ) * 19 % 20;
        b[i][1] = b[i][0] * 19 % 20;
    }
    for( i = 0; i < 20; i++ )
        printf("%d ", a[i]);
    printf("\n");
    for( i = 0; i < 20; i++ )
    {
        printf("%d %d", b[i][0], b[i][1]);
        printf("\n");
    }
    qsort( a, 20, sizeof(int), compare );
    qsort( b, 20, sizeof(int) * 2, compare );
    for( i = 0; i < 20; i++ )
        printf("%d ", a[i]);
    printf("\n");
    for( i = 0; i < 20; i++ )
    {
        printf("%d %d", b[i][0], b[i][1]);
        printf("\n");
    }
    return 0;
}

int compare( const void * a, const void * b )
{
    return *(int*)a - *(int*)b;
}
