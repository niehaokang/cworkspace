/*************************************************************************
	> File Name: lantern.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月20日 星期四 12时03分25秒
 ************************************************************************/

#include<stdio.h>
void swap( int *a, int *b );
int main()
{
    int i, j;
    int m, n;
    int temp;
    int result;
    scanf("%d %d", &m, &n);
    int a[n][2];
    for( i = 0; i < n; i++ )
        scanf("%d %d", &a[i][0], &a[i][1]);
    for( i = 0; i < n; i++ )
    {
        for( j = 0; j < n - i - 1; j++ )
        {
            if( a[j][0] > a[j + 1][0] )
            {
                swap(&a[j][0], &a[j+1][0]);
                swap(&a[j][1], &a[j+1][1]);
            }
        }
    }
    /*
    for( i = 0; i < n; i++ )
        printf("%d %d\n", a[i][0], a[i][1]);
    */
    for( i = 0; i < n; i++ )
    {
        temp = a[i][0];
        while( a[i][1] > a[i+1][0] )
        {
            i++;
        }
        result += a[i][1] - temp + 1;
    }
    printf("%d\n", m + 1 - result);
    return 0;
}

void swap( int *a, int *b )
{
    int temp; 
    temp = *a;
    *a = *b;
    *b = temp;
}
