/*************************************************************************
	> File Name: reverse.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月08日 星期六 12时23分35秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int reverse( int n );

int main()
{
    int m, n;
    n = 1534236469;
    m = reverse(n);
    printf("m = %d\n", m);
    return 0;
}
/*
int reverse( int n )
{
    int m = 0;
    while(n)
    {
        if(m > 214748364 || m < -214748364)
            return 0;
        m = m * 10 + n%10;
        n = n/10;
    }
    return m;
}
*/
int reverse( int n )
{
    int i, j;
    int temp;
    int sign = 1;
    int abs_n = n;
    int len;
    char c[32];
    char max_c[] = "2147483647";
    if (n < 0)
    {
        abs_n = -n;
        sign = -1;
    }
    sprintf(c, "%d", abs_n);
    len = strlen(c);
    for(i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = c[i];
        c[i] = c[j];
        c[j] = temp;
    }
    if(strlen(c) > strlen(max_c) || (strlen(c) == strlen(max_c) && strcmp(c, max_c) > 0))
        return 0;
    printf("%d", atoi(c));
    return sign * atoi(c);
}
