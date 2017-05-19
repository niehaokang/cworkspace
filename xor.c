/*************************************************************************
	> File Name: xor.c
	> Author: Datou_Nie
	> Mail: 
	> Created Time: 2017年04月09日 星期日 21时07分55秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
    int i;
    int result = 0;
    scanf("%d", &n);
    char num1[n+1];
    char num2[n+2];
    scanf("%s", num1);
    scanf("%s", num2);
    for( i = 0; i < n; i++ )
    {
        result = result << 1;
        result += (num1[i] == num2[i])? 0 : 1;
        
    }
        printf("%d\n", result);
    return 0;
}
