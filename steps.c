/*************************************************************************
	> File Name: steps.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月08日 星期四 15时47分43秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i, j;
    int m, n;
    scanf("%d", &n);
    for( i = 0; i < n; i++ )
    {
        scanf("%d", &m);
        int dp[m + 1];
        dp[1] = 1;
        dp[2] = 1;
        for( j = 3; j <= m; j++  )
            dp[j] = dp[j - 1] + dp[j - 2];
        printf("%d\n", dp[m]);
    }
    return 0;
}
