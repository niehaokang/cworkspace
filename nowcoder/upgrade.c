/*************************************************************************
	> File Name: upgrade.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月22日 星期六 14时11分06秒
 ************************************************************************/

#include<stdio.h>

int GCD(long a, int b);

int main()
{
    int i;
    int n;
    long m;
    while(scanf("%d %ld", &n, &m) != EOF)
    {
        int a[n];
        for( i = 0; i < n; i++ )
            scanf("%d", &a[i]);
        for( i = 0; i < n; i++ )
        {
            if( m >= a[i] )
                m += a[i];
            else
                m += GCD(m, a[i]);
        }
        printf("%ld\n", m);
    }
    return 0;
}

int GCD( long a, int b )
{
    if( b == 0 )
        return a;
    else
        return GCD( b, a % b );
}
