/*************************************************************************
	> File Name: decline.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月24日 星期一 13时57分10秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int i, j, k;
    int n;
    scanf("%d", &n);
    for( i = 0; i < n; i ++ )
    {
        int num;
        int max = 0;
        scanf("%d", &num);
        int a[num];
        int dp[num];
        for(j = 0; j < num; j++)
            scanf("%d", &a[j]);
        for( j = 0; j < num; j++ )
            dp[j] = 1;
        dp[0] = 1;
        for( j = 1; j < num; j++ )
            for( k = 0; k < j; k++ )
            {
                if(a[k] > a[j] && dp[k] >= dp[j])
                    dp[j] = dp[k] + 1; 
            }
        for( j = 0; j < num; j++ )
            if( dp[j] > max )
                max = dp[j];
        printf("%d\n", max);
    }
    return 0;
}
