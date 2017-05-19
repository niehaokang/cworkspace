/*************************************************************************
	> File Name: palindrome.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月18日 星期二 21时23分54秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i, j;
    int n;
    int htemp, ttemp;
    int count = 0;
    scanf("%d", &n);
    int a[n];
    for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    i = 0;
    j = n - 1;
    while(i < j)
    {
        if(a[i] == a[j])
        {
            i++;
            j--;
        }
        else if( a[i] > a[j] )
        {
            j--;
            a[j] += a[j + 1];
            count++;
        }
        else
        {
            i++;
            a[i] += a[i - 1];
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
