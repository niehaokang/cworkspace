/*************************************************************************
	> File Name: assic.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月21日 星期一 18时28分14秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i = 0;
    char str[] = "Hello World!";
    while( str[i] != '\0' )
    {
        printf("%x ", str[i]);
        i++;
    }
    return 0;
}
