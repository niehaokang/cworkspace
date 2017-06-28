/*************************************************************************
	> File Name: max_interval.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月09日 星期五 09时31分33秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i;
    int n;
    int temp_1, temp_2;
    int max_interval_1, min_interval_2;
    scanf("%d", &n);
    int a[n];
    for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    max_interval_1 = a[1] - a[0];
    min_interval_2 = a[2] - a[0];
    for( i = 1; i < n - 2; i++ )
    {
        temp_1 = a[i+1] - a[i];
        if( temp_1 > max_interval_1 )
            max_interval_1 = temp_1;
        temp_2 = a[i+2] - a[i];
        if( temp_2 < min_interval_2 )
            min_interval_2 = temp_2;
    }
    if( max_interval_1 < a[i+1] - a[i] )
        max_interval_1 = a[i+1] - a[i];
    printf("%d\n", (max_interval_1 >= min_interval_2)? max_interval_1:min_interval_2);
    return 0;
}
