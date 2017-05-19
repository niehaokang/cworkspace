/*************************************************************************
	> File Name: load.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月22日 星期六 13时13分38秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i;
    int n, m;
    scanf("%d %d", &n, &m);
    int count = 0;
    int temp = m;
    int a[n];
    for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    i = 0;
    while(i < n)
    {
        if( temp >= a[i] )
        {
            temp = temp - a[i++];
        }
        else
        {
            count++;
            temp = m;
        }
    }
    if( temp >= 0 )
        count++;
    printf("%d\n", count);
    return 0;
}
