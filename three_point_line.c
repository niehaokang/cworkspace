/*************************************************************************
	> File Name: three_point_line.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月22日 星期六 15时33分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int compInc(const void *a, const void *b)  
{  
    return *(int *)a - *(int *)b;  
}  

int main()
{
    int i, j = 0;
    int temp, result = 0x80000000;
    int n, m;
    scanf("%d", &n);
    int a[n];
    for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    scanf("%d", &m);
    int b[m];
    for( i = 0; i < m; i++ )
        scanf("%d", &b[i]);
    qsort(a, n, sizeof(int), compInc);
    qsort(b, m, sizeof(int), compInc);
    for( i = 0; i < n; i++ )
    {
        for(; j < m; j++ )
        {
            if( b[j] > a[i] )
                break;
        }
        temp = (n - i) * 3 + i * 2 - j * 2 - (m - j) * 3; 
        if( temp > result )
            result = temp;
        while( a[i] < b[j] )
            i++;
    }
    if( j < m )
    {
        temp = 2 * ( n - m );
        if( temp > result )
            result = temp;
    }
    printf("%d\n", result);
    return 0;
}
