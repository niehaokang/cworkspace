/*************************************************************************
	> File Name: blackstring.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月18日 星期二 22时22分22秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i;
    int n;
    scanf("%d", &n);
    long dp[32];
    dp[1] = 3;
    dp[2] = 9;
    for( i = 3; i <= n; i++ )
        dp[i] = 2 * dp[i-1] + dp[i - 2];
    printf("%ld", dp[n]);
    return 0;
}
