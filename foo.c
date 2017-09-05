/*************************************************************************
	> File Name: foo.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月15日 星期二 10时35分17秒
 ************************************************************************/

#include<stdio.h>

int foo();
int bar();

int main(void)
{
	foo(2, 3, 4);
	return 0;
}

int foo(int a, int b)
{
	return bar(a);
}

int bar(int c, int d)
{
	int e = c + d;
	return e;
}


