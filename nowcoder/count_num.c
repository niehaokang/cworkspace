/*************************************************************************
	> File Name: count_num.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月08日 星期四 19时29分45秒
 ************************************************************************/

#include<stdio.h>

int judge( int num )
{
    if( num % 7 == 0 )
        return 1;
    else
    {
        while( num )
        {
            if( num % 10 == 7 )
                return 1;
            else
                num = num / 10;
        }
    }
    return 0;
}

int main()
{
    int n, m, k;
    int round = 0;
    int num;
    while( 1 )
    {
        scanf("%d %d %d", &n, &m, &k);
        if( n == 0 && m == 0 && k == 0 )
            break;
        num = m;
        while( k > 0 )
        {
            if( judge( num ) )
                if( !(--k) )
                    break;
            if( round % 2 ==  0 )
                num += 2 * (n - m);
            else
                num += 2 * (m - 1); 
            round++;
        }
        printf("%d\n", num);
    }
    return 0;
}
