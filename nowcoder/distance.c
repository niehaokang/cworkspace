/*************************************************************************
	> File Name: distance.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月09日 星期五 10时43分42秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int a, b, c, d;
    int sum = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while( a != 0 )
    {
        sum += a;
        a = a/2;
        sum += a;
    }
    while( b != 0 )
    {
        sum += b;
        b = b/2;
        sum += b;
    }
    while( c != 0 )
    {
        sum += c;
        c = c/2;
        sum += c;
    }
    while( d != 0 )
    {
        sum += d;
        d = d/2;
        sum += d;
    }
    printf("%d\n", sum);
    return 0;
}
