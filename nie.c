/*************************************************************************
	> File Name: nie.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月07日 星期日 20时26分37秒
 ************************************************************************/

#include<stdio.h>
int a, b;

int add1( int a, int b )
{
    printf("%d %d\n", a, b);
    return 0;
}

int add(int *a, int *b )
{
    add1(*a, *b);
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("%d %d\n", *a, *b);
    return 4;
}

int main()
{
    a = 3; b = 4;
    printf("%d\n", add( &a, &b ));
    printf("%d %d\n", a, b);
    printf("%p %p\n", &a, &b);
    return 0;
}
