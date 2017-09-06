/*************************************************************************
	> File Name: fibonacci.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月16日 星期日 14时41分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000000000

unsigned long fibonacci( unsigned long n );

unsigned long my_fibonacci_matrix( unsigned long n );

int main()
{
    int n = 50;
    my_fibonacci_matrix(n);
    printf("%ld\n", my_fibonacci_matrix(n));
    fibonacci( n );
    printf("%ld\n", fibonacci(n));
    return 0;
}

unsigned long fibonacci( unsigned long n )
{
    unsigned long one = 0;
    unsigned long two = 1;
    unsigned long fib;
    if( n == 0 )
        return 0;
    else if( n == 1 )
        return 1;
    else if( n > 1 )
    {
        unsigned long i;
        for( i = 2; i <= n; i++ )
        {
            fib = (one + two) % N;
            one = two % N;
            two = fib;
        }
        return fib;
    }
}

unsigned long my_fibonacci_matrix( unsigned long n )
{
    if( n == 1 || n == 2)
        return 1;
    unsigned long n_2 = n - 2;
    unsigned long a[2][2] = {1, 0, 0, 1};
    unsigned long b[2][2] = {1, 1, 1, 0};
    unsigned long c[2][2];
    while( n_2 != 0 )
    {
        if( n_2 & 1)
        {
            c[0][0] = ((a[0][0] * b[0][0]) % N + (a[0][1] * b[1][0]) % N) % N;
            c[0][1] = ((a[0][0] * b[0][1]) % N + (a[0][1] * b[1][1]) % N) % N;
            c[1][0] = ((a[1][0] * b[0][0]) % N + (a[1][1] * b[1][0]) % N) % N;
            c[1][1] = ((a[1][0] * b[0][1]) % N + (a[1][1] * b[1][1]) % N) % N;
            memcpy(a, c, 4 * sizeof(long));
        }
            c[0][0] = ((b[0][0] * b[0][0]) % N + (b[0][1] * b[1][0]) % N) % N;
            c[0][1] = ((b[0][0] * b[0][1]) % N + (b[0][1] * b[1][1]) % N) % N;
            c[1][0] = ((b[1][0] * b[0][0]) % N + (b[1][1] * b[1][0]) % N) % N;
            c[1][1] = ((b[1][0] * b[0][1]) % N + (b[1][1] * b[1][1]) % N) % N;
            memcpy(b, c, 4 * sizeof(long));
            n_2 >>= 1;
    }
    return (a[0][0] + a[0][1]) % N;
}
