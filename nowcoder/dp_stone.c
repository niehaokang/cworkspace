/*************************************************************************
	> File Name: dp_stone.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月18日 星期二 18时20分59秒
 ************************************************************************/

#include<stdio.h>
#include<limits.h>
#include<string.h>
unsigned int min( unsigned int a, unsigned int b );
int main()
{
    int i, j;
    unsigned int n, m;
    scanf("%d %d", &n, &m);
    unsigned int step[m + 9];
    for( i = n; i <= m; i++ )
        step[i] = UINT_MAX;
    step[n] = 0;
    for( i = n; i <= m; i++ )
    {
        if(step[i] == UINT_MAX)
            continue;
        for( j = 2; j * j <= i; j++ )
        {
            if( i % j == 0 )
            {
                if(i + j <= m)
                    step[i + j] = min(step[i] + 1, step[i + j]);
                if(i + i/j <= m)
                    step[i + i/j] = min(step[i] + 1, step[i + i/j]);
            }
        }
    }
    if(step[m] == UINT_MAX)
        printf("%d\n", -1);
    else
        printf("%d\n",step[m]);
    return 0;
}

unsigned int min( unsigned int a, unsigned int b )
{
    return (a <= b)? a:b; 
}
