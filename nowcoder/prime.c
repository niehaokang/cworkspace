/*************************************************************************
	> File Name: prime.c
	> Author: Datou_Nie
	> Mail: 
	> Created Time: 2017年04月18日 星期二 20时16分28秒
 ************************************************************************/

#include<stdio.h>
#include<limits.h>
int main()
{
    int i, j;
    int primes[10000];
    int index = 0;
    long long a = 181783497276652981;
    primes[index++] = 2;
    primes[index++] = 3;
    primes[index++] = 5;
    for( i = 7; i < INT_MAX; i++ )
    {
        for( j = 0; primes[j] * primes[j] < i; j++ )
        {
            if(i % primes[j] == 0)
                break;
        }
        if( primes[j] * primes[j] > i )
            primes[index++] = i;
        if(index > 9999)
            break;
    }
    /*
    for( i = 0; i < 10000; i++ )
        printf("%d\n", primes[i]);
    */
    printf("index = %d", index);
    return 0;
}
