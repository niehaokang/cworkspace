/*************************************************************************
	> File Name: sizeof.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月22日 星期一 15时46分14秒
 ************************************************************************/

#include<stdio.h>

struct test{
}test;

int main()
{
    printf("sizeof(test) = %d\n", (int)sizeof(test));
    printf("sizeof(char) = %d \n", (int)sizeof(char));
    printf("sizeof(int) = %d \n", (int)sizeof(int));
    printf("sizeof(long) = %d \n", (int)sizeof(long));
    printf("sizeof(long long) = %d \n", (int)sizeof(long long));
    printf("sizeof(char *) = %d \n", (int)sizeof(char *));
    printf("sizeof(int *) = %d \n", (int)sizeof(int *));
    printf("sizeof(long *) = %d \n", (int)sizeof(long *));
    printf("sizeof(long long *) = %d \n", (int)sizeof(long long *));
    return 0;
}
