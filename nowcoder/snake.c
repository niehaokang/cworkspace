/*************************************************************************
	> File Name: snake.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月12日 星期五 15时01分21秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    int i, j = 0, k = 1;
    int nn = n;
    while( j < n/2 )
    {
        for( i = j; i < nn - j; i++ )
            a[i][nn - 1 - j] = k++;
        for( i = nn - j - 2; i >= j; i-- )
            a[nn - 1 - j][i] = k++;
        for( i = nn - 2 - j; i >= j; i-- )
            a[i][j] = k++;
        for( i = j + 1; i < n - 1 - j; i++ )
            a[j][i] = k++;
        j++;
    }
    if( n % 2 == 1 )
        a[j][j] = k;
    for( i = 0; i < n; i++ )
    {
        for( j = 0; j < n; j++ )
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
