/*************************************************************************
	> File Name: chat.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月23日 星期日 09时50分43秒
 ************************************************************************/

#include<stdio.h>
/*
void swap( int *a, int *b );
void buble_sort( int a[][2], int n );
*/

int main()
{
    int i, j, k;
    int count = 0;
    int flag;
    int p, q, l, r;
    int as, ae, bs, be;
    scanf("%d %d %d %d", &p, &q, &l, &r);
    int a[p][2];
    int b[q][2];
    for( i = 0; i < p; i++ )
        scanf("%d %d", &a[i][0], &a[i][1]);
    for( i = 0; i < q; i++ )
        scanf("%d %d", &b[i][0], &b[i][1]);
    /*
    buble_sort(a, p);
    buble_sort(b, q);
    for( i = 0; i < p; i++ )
        printf("%d %d\n", a[i][0], a[i][1]);
    for( i = 0; i < q; i++ )
        printf("%d %d\n", b[i][0], b[i][1]);
    */
    for( k = l; k <= r; k ++ )
    {
        for( i = 0; i < p; i++ )
        {
            flag = 0;
            as = a[i][0];
            ae = a[i][1];
            for( j = 0; j < q; j++ )
            {
                bs = b[j][0] + k;
                be = b[j][1] + k;
                if( as > be || bs > ae )
                    continue;
                else
                {
                    count++;
                    flag = 1;
                    break;
                }
            }
            if( flag )
                break;
        }
    }
    printf("%d\n", count);
    return 0;
}
/*
void swap( int *a, int *b )
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void buble_sort(int a[][2], int n)
{
    int i, j;
    int count;
    int temp;
    for( i = 0; i < n; i++ )
    {
        count = 0;
        for( j = 0; j < n - i - 1; j++ )
        {
            if( a[j][0] > a[j + 1][0] )
            {
                count++;
                swap(&a[j][0], &a[j + 1][0]);
                swap(&a[j][1], &a[j + 1][1]);
            }
        }
        if(count == 0)
            break;
    }
}
*/
