/*************************************************************************
	> File Name: date.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月21日 星期五 10时48分42秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int a, b, s;
    scanf("%d %d %d", &a, &b, &s);
    int distance = a + b;
    if( s < distance || ( s- distance ) / 2 == 1 )
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
