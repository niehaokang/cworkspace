/*************************************************************************
	> File Name: pass_exam.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月09日 星期日 18时33分27秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define N 101
int main()
{
    int i, j;
    int n;
    int low;
    double ans = 0;
    int a[N];
    double p[N][N];

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    p[0][0] = 1;

    for( i = 1; i <= n; i++ )
    {
        p[i][0] = p[i-1][0] * (1- a[i]/100.0);
        for( j = 1; j <= i; j++ )
            p[i][j] = p[i-1][j] * (1 - a[i]/100.0) + p[i-1][j-1] * (a[i]/100.0);
    }

    low = ceil(n * 0.6);
    for( i = low; i <= n; i++ )
        ans += p[n][i];
    printf("%.5f\n", ans);
    return 0;
}
