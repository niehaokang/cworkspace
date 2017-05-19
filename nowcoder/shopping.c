/*************************************************************************
	> File Name: shopping.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月04日 星期四 21时48分46秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i, j;
    int temp, count = 0;
    int n, v;
    scanf("%d %d", &n, &v);
    int a[n];
    for( i = 0; i < n; i++)
    scanf("%d", &a[i]);
    for( i = 0; i < n; i++)
    for( j = 0; j < n - i - 1; j++)
        if( a[j] > a[j + 1])
        {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    for( i = 0; i < n; i++)
    {
    if(count >= v)
        break;
    else
        count += a[i];
    }
    printf("%d\n", i - 1);
    return 0;
}
