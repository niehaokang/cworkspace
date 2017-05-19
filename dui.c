/*************************************************************************
	> File Name: dui.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月09日 星期日 19时14分14秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n, k;
    int num;
    scanf("%d %d", &n,&k);
    num = n / (2*k + 1) * 2;
    if( n % ( 2 * k + 1 ) / k )
        num += 1;
    printf("%d", num);
    return 0;
}
