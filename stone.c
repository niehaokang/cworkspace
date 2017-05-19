/*************************************************************************
	> File Name: stone.c
	> Author:
	> Mail:
	> Created Time: 2017年04月18日 星期二 10时19分29秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int GCD(int a, int b);
int GCD_2(int n);
int isPrime( int n );

int main()
{
    int n, m, gcd;
    int index = 0;
    int step_len[30];
    int count = 0;
    scanf("%d %d", &n, &m);
    if( isPrime(n) || GCD(m, n) == 1)
        printf("%d\n", -1);
    else
    {
        while( n < m )
        {
            gcd = GCD(m, n);
            if( gcd == n )
                gcd = GCD_2(gcd);
            else if(!isPrime(n / gcd) )
            {
                gcd *= GCD_2( n / gcd );
            }
            if(gcd != step_len[index -1])
                step_len[index++] = gcd;
            n += gcd;
            count++;
        }
        if( n > m )
        {
            count--;
            index--;
            n -= gcd;
            int sub;
            while( n != m )
            {
                sub = m - n;
                while( step_len[index] > sub )
                    index --;
                n += step_len[index];
                count++;
            }
        }
        printf("%d", count);
    }
    return 0;
}

int GCD(int a, int b)
{
    int result;
    if( b != 0 )
    {
        a = a % b;
        result = GCD( b, a );
    }
    else
        return a;
    return result;
}

int GCD_2(int n)
{
    int i;
    for( i = 2; i * i <= n; i++ )
        if( n % i == 0 )
            return n / i;
    return 1;
}

int isPrime( int n )
{
    int i;
    for( i = 2; i * i <= n; i++ )
        if( n % i == 0 )
            return 0;
    return 1;
}
