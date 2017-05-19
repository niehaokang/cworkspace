/*************************************************************************
	> File Name: similar.c
	> Author: Datou_Nie
	> Mail: 
	> Created Time: 2017年04月12日 星期三 10时57分54秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define decision(c) (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
int Decision(char c)
{
    return (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}
    
int main()
{
    int i;
    int count = 0;
    char str[1009];
    char str1[1009];
    scanf("%s", str);
    scanf("%s", str1);
    int len = strlen(str);
    for( i = 0; i < len; i++ )
    {
        if(Decision(str[i]) ^ str1[i] == '1')
            continue;
        count++;
    }
    printf("%.2f%%\n", (double)100 * count/len);
    return 0;
}
