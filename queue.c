/*************************************************************************
	> File Name: queue.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月08日 星期四 16时32分53秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i, j;
    int m, n;
    int queue[50001][2];
    scanf("%d", &n);
    for( i = 0; i < n; i++ )
    {
        scanf("%d", &m);
        int num = m;
        for( j = 1; j <= m; j++ )
        {
            queue[j][0] = j;
            queue[j][1] = j;
        }
        while( num > 3 )
        {
            for( j = 1; j <= m; j++  )
            {
                if( queue[j][1] != 0 && queue[j][0] % 2 == 0 )
                    queue[j][1] = 0;
                else
                    queue[j][0] -= queue[j][0] / 2;
            }
            num -= num/2;
            if( num <= 3 )
                break;
            for( j = 1; j <= m; j++  )
            {
                if( queue[j][1] != 0 && queue[j][0] % 3 == 0 )
                    queue[j][1] = 0;
                else
                    queue[j][0] -= queue[j][0] / 3;
            }
            num -= num/3;
            if( num <= 3 )
                break;
        }
        for( j = 0; j <= m; j++ )
            if( queue[j][1] != 0 )
                printf("%d ", queue[j][1]);
    }
    return 0;
}
