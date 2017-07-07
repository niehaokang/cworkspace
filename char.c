/*************************************************************************
	> File Name: char.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月18日 星期日 13时25分42秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    char a = 'P';
    char b = 'E';
    printf("%x\n", a);
    printf("%x\n", b);
    char c = 40;
    char d = 41;
    printf("%c\n", c);
    printf("%c\n", d);
    printf("%d\n", '\0');
    printf("%d\n", 0);
    printf("%d\n", '\0' == 0);
    printf("%d\n", (int)(sizeof(long)));
    return 0;
}
