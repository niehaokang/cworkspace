/*************************************************************************
	> File Name: operator_sequence.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月12日 星期六 15时29分09秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i, j, k;
    int flag = 1;
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];
    for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    j = 0;
    k = n - 1;
    for( i = n - 1; i >= 0; i-- )
    {
        if( flag )
        {
            b[j++] = a[i];
            flag = 0;
        }
        else
        {
            b[k--] = a[i];
            flag = 1;
        }
    }
    for( i = 0; i < n; i++ )
        printf("%d ", b[i]);
    return 0;
}
