/*************************************************************************
	> File Name: str.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月02日 星期三 20时01分00秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    const char *a = "aaa";
    const char *b = "bbb";
    char strfirst[10];
    char strsecond[10];
    strcpy( strfirst, a );
    strcat( strfirst, b );
    strcpy( strsecond, b );
    strcat( strsecond, a );
    printf("%s\n", strfirst);
    printf("%s\n", strsecond);
    return 0;
}
