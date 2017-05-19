/*************************************************************************
	> File Name: findThief.c
	> Author: Datou_Nie
	> Mail: 
	> Created Time: 2017年04月09日 星期日 19时51分52秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    int i = 0, j;
    int n;
    int  x;
    int total = 0;
    scanf("%d", &n);
    int index[n];
    char c[n + 1];
    scanf("%s", c);
    memset(index, 0, sizeof(index));

    while( i < n )
    {
        if( c[i] >= '0' && c[i] <= '9' )
        {
            x = c[i] - '0';
            for( j = 1; j <= x; j++ )
            {
                printf("%d, %d, %c, %c\n", i, j, c[i-j], c[i+j]);

                if(c[i-j] == 'X' && i >= j)
                {
                    index[i-j]++;
                    printf("index[i-j] = %d\n", index[i-j]);
                }
                if(c[i+j] == 'X' && n > (i + j))
                {
                    index[i+j]++;
                    printf("index[i+j] = %d\n", index[i+j]);
                }
            }
        }
        i++;
    }

    for( j = 0; j < n; j++ )
    {
        if(index[j] > 0)
            total++;
    }

    printf("%d", total);

    return 0;
}
