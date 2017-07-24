/*************************************************************************
	> File Name: fibonacci.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月16日 星期日 14时41分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long fibonacci( int N );

long fibonacci_matrix( int N );

int main()
{
    int i;
    int n = 12;
    for( i = 0; i < 1 << 25; i++ )
//        fibonacci_matrix(n);
//    printf("%ld\n", fibonacci_matrix(n));
        fibonacci( n );
    printf("%ld\n", fibonacci(n));
    return 0;
}

long fibonacci( int N )
{
    long one = 0;
    long two = 1;
    long fib;
    if( N < 0 )
    {
        printf("Bad input...\n");
        exit(-1);
    }
    if( N == 0 )
        return 0;
    else if( N == 1 )
        return 1;
    else if( N > 1 )
    {
        int i;
        for( i = 2; i <= N; i++ )
        {
            fib = one + two;
            one = two;
            two = fib;
        }
        return fib;
    }
}

long fibonacci_matrix( int N )
{
    int num = (N + 1) / 2;
    long temp[2][2];
    long matrix[2][2] = {2, 1, 1, 1};
    long result[2][2] = {1, 0, 0, 1};
    while( num != 0 )
    {
        if(num & 1)
        {
            temp[0][0] = result[0][0] * matrix[0][0] + result[0][1] * matrix[1][0];
            temp[0][1] = result[0][0] * matrix[0][1] + result[0][1] * matrix[1][1];
            temp[1][0] = result[1][0] * matrix[0][0] + result[1][1] * matrix[1][0];
            temp[1][1] = result[1][0] * matrix[0][1] + result[1][1] * matrix[1][1];
            result[0][0] = temp[0][0];
            result[0][1] = temp[0][1];
            result[1][0] = temp[1][0];
            result[1][1] = temp[1][1];
        }
        temp[0][0] = matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[1][0];
        temp[0][1] = matrix[0][0] * matrix[0][1] + matrix[0][1] * matrix[1][1];
        temp[1][0] = matrix[1][0] * matrix[0][0] + matrix[1][1] * matrix[1][0];
        temp[1][1] = matrix[1][0] * matrix[0][1] + matrix[1][1] * matrix[1][1];
        matrix[0][0] = temp[0][0];
        matrix[0][1] = temp[0][1];
        matrix[1][0] = temp[1][0];
        matrix[1][1] = temp[1][1];
        num = num >> 1;
    }
    if( N & 1 )
        return result[1][1];
    else
        return result[0][1];
}
