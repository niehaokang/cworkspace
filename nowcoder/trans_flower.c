/*************************************************************************
	> File Name: trans_flower.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月24日 星期一 11时51分59秒
 ************************************************************************/

#include<stdio.h>

unsigned int combination(int n, int k);

int main()
{
    int i, j, k = 0;
    int n, m;
    unsigned int result = 0;
    scanf("%d %d", &n, &m);
    for( i = 0, j = m; i < j; i++, j-- )
    {
        if( ( i - j ) % n == 0)
            result += 2 * combination(m, i);
    }
    if( i == j )
       result += combination(m, i); 
    printf("%d", result);
    return 0;
}

unsigned int combination( int n, int k )
{
    int i = 0;
    unsigned int result = 1;
    for( i = 0; i < k; i ++ )
       result = (result * (n - i) / (i + 1));  
    printf("C(%d,%d) = %d\n", n, k, result);
    return result;
}
