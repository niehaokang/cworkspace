/*************************************************************************
	> File Name: ford_dp.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月24日 星期一 15时03分50秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    int i, j, k;
    int n;
    int max = 0;
    scanf("%d", &n);
    int a[n - 1][3];
    unsigned dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for(i = 0; i < n - 1; i++) 
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    for( k = 0; k < n - 1; k++ )
    {
        dp[a[k][0]][a[k][1]] = a[k][2]; 
        dp[a[k][1]][a[k][0]] = a[k][2]; 
    }
    /*
    for( i = 1; i < n + 1; i++ )
    {
        for( j = 1; j < n + 1; j++ )
            printf("%d ", dp[i][j]);
        printf("\n");
    }
    */
    for( i = 1; i < n + 1; i++ )
    {
        for(j = 1; j < n + 1; j++)
        {
            if( dp[i][j] > 0 )
            {
                k = j + 1;
                while( k < n + 1 )
                {
                    if( dp[i][k] > 0 )
                    {
                        if( dp[j][k] == 0 )
                        {
                            dp[j][k] = dp[i][j] + dp[i][k];
                            dp[k][j] = dp[i][j] + dp[i][k];
                        }
                    }
                    k++;
                }
            }
        }
    }
    for( i = 1; i < n + 1; i++ )
        for( j = i + 1; j < n + 1; j++ )
        {
            if( dp[i][j] > max )
                max = dp[i][j];
        }
    max = max * 10 + max * (1 + max ) / 2 ;
    printf("%d\n", max);
    return 0;
}
