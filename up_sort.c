/*************************************************************************
	> File Name: up_sort.c
	> Author: Datou_Nie
	> Mail: 
	> Created Time: 2017年04月12日 星期三 10时07分15秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i = 0;
    int temp0, temp0_0, temp1, temp1_1;
    int n;
    scanf("%d", &n);
    int a[n];
    for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    if( a[0] < a[1] )
    {
        for( i = 2; i < n; i++ )
            if( a[i] < a[i - 1] )
                break;
        temp0 = i - 2;
        temp1 = i - 1;
        if( i < n)
        {
            for( ; i < n; i++ )
                if( a[i] > a[i - 1] )
                    break;
        }
        temp0_0 = i - 1;
        temp1_1 = i;
        if( a[temp0] > a[temp0_0] || a[temp1] > a[temp1_1])
        {
            printf("no\n");
            return 0;
        }
        if(i < n)
        {
            for( ; i < n; i++ )
                if( a[i] < a[i - 1] )
                    break;
        } 
    }
    else
    {
        temp0 = 0;
        for( i = 2; i < n; i++ )
            if( a[i] > a[i - 1] )
                break;
        if(a[temp0] < a[i] && i < n)
        {
            for( ; i < n; i++ )
                if( a[i] < a[i - 1] )
                    break;
        } 
    }
    if(i == n)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
