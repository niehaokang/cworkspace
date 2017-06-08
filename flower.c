/*************************************************************************
	> File Name: flower.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月08日 星期四 16时06分20秒
 ************************************************************************/

#include<stdio.h>

unsigned int cmi( int m , int i )
{
    int j;
    unsigned int num = 1;
    for( j = 1; j <= i; j++ )
    {
        num *= ( m + 1 - j );
        num /= j;
    }
    printf("num = %d\n", num);
    return num;
}

int main()
{
    int i;
    int m, n;
    int num = 0;
    scanf("%d %d", &n, &m);
    for( i = 0; i < m / 2; i++ )
    {
        if( (m - 2 * i) % n == 0 )
            num += 2 * cmi( m, i ); 
    }
    if( m % 2 == 0 )
        num += cmi( m, m/2 );
    printf("%d\n", num);
}
