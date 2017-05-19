/*************************************************************************
	> File Name: grid.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月12日 星期五 11时15分47秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i, j;
    int n, m;
    int count, max;
    scanf("%d %d", &n, &m);
    int a[n + 1];
    int op[m][3];
    for( i = 1; i <= n; i++ )
        scanf("%d", &a[i]);
    for( i = 0; i < m; i++ )
        scanf("%d %d %d", &op[i][0], &op[i][1], &op[i][2]);
    for( i = 0; i < m; i++ )
    {
        if(op[i][0] == 1)
            a[op[i][1]] = op[i][2];
        else if(op[i][0] == 2)
        {
            count = 0;
            for( j = op[i][1]; j <= op[i][2]; j++ )
                count += a[j];
            printf("%d\n", count);
        }
        else if(op[i][0] == 3)
        {
            max = 0;
            for( j = op[i][1]; j <= op[i][2]; j++ )
                if( a[j] > max )
                    max = a[j];
            printf("%d\n", max);
        }
    }
    return 0;
}
