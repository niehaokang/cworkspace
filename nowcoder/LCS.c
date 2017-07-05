/*************************************************************************
	> File Name: LCS.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月04日 星期二 18时04分49秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int LCS( char *a, char *b );

int main()
{
    char a[10] = "BDCABA";
    char b[10] = "ABCBDAB";
    int len = LCS( a, b );
    printf("LCS of a, b = %d\n", len);
    return 0;
}

static int max( int a, int b )
{
    return a > b ? a:b;
}

int LCS( char *a, char *b )
{
    int i, j;
    int la = strlen(a);
    int lb = strlen(b);
    int c[la][lb];
    for( i = 0; i < la; i++ )
        c[i][0] = 0;
    for( i = 0; i < lb; i++ )
        c[0][i] = 0;
    for( i = 1; i <= la; i++ )
    {
        for( j = 1; j <= lb; j++ )
        {
            if( a[i] == b[j] )
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max( c[i-1][j], c[i][j-1] );
        }
    }
    return c[la][lb];
}
