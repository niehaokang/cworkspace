/*************************************************************************
	> File Name: sprintf.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月08日 星期六 12时10分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i;
    int n = 65535;
    int m;
    char c[32];
    memset(c, 0, sizeof(c));
    sprintf(c, "%d", n);
    for(i = 0; i < 10; i++)
        printf("%c ", c[i]);
    printf("\n");
    m = atoi(c);
    printf("m = %d\n", m);
    return 0;
}
