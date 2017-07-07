/*************************************************************************
	> File Name: mergearray.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月06日 星期四 11时06分02秒
 ************************************************************************/

#include<stdio.h>

void mergearray( int *a, int la, int *b, int lb );
void print(int *a, int len);

int main(int argc, char *argv[])
{
    int a[20] = { 0, 0, 0, 1, 3, 5, 7, 9 };
    int b[10] = { 0, 2, 4, 6, 8 };
    mergearray( a, 8, b, 5 );
    print(a, 13);
    return 0;
}

void print(int *a, int len)
{
    int i;
    for( i = 0; i < len; i++ )
        printf("%d", a[i]);
}

void mergearray( int *a, int la, int *b, int lb)
{
    if( a != NULL )
    {
        if( b == NULL || lb == 0 )
            return;
        int len = la + lb;
        la--;
        lb--;
        len--;
        while( la >= 0 && lb >= 0 )
        {
            if(b[lb] >= a[la])
                a[len--] = b[lb--];
            else
                a[len--] = a[la--];
        }
        while( lb >= 0 )
            a[len--] = b[lb--];
    }
}
