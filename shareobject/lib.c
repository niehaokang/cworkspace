/*************************************************************************
	> File Name: lib.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月28日 星期三 13时27分54秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

void foobar(int i)
{
    printf("printing frome lib.so %d\n", i);
    sleep(-1);
}
