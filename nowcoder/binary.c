/*************************************************************************
	> File Name: binary.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月04日 星期四 20时05分12秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int count( int i );

int main()
{
    int i;
    int cnt = 0;
    int l, r, m;
    scanf("%d %d %d", &l, &r, &m);
    for( i = l; i <= r; i++ )
        if(count( i ) == m)
            cnt++;
    if( cnt  == 0 )
        printf("-1\n");
    else
        printf("%d\n", cnt);
    return 0;
}

int count( int i )
{
    int count = 0;
    while( i )
    {
        i = i & (i - 1);
        count++;
    }
    return count;
}
