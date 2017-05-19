/*************************************************************************
	> File Name: step.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月21日 星期五 09时27分57秒
 ************************************************************************/

#include<stdio.h>
int fib( int n )
{
    if( n == 2 )
        return 1;
    else if ( n == 3)
        return 2;
    else 
        return fib( n - 1 ) + fib( n - 2 );
}

int main()
{
    int i;
    int n;
    scanf("%d", &n);
    int a[n];
    for ( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    for ( i = 0; i < n; i++ )
        printf("%d\n", fib(a[i]));
    return 0;
}
