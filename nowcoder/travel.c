/*************************************************************************
	> File Name: travel.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月08日 星期四 17时23分14秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i;
    int times = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    int dis[m + 1];
    for( i = 0; i <= m; i++ )
        scanf("%d", &dis[i]);
    int temp = n;
    for( i = 0; i <= m; i++ )
    {
        if( dis[i] > n )
        {
            times = 0;
            break;
        }
        else
        {
            temp -= dis[i];
            if( temp >= dis[i + 1] )
                continue;
            else
            {
                times++;
                temp = n;
            }
        }
    }
    printf("%d\n", times);
    return 0;
}
