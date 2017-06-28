/*************************************************************************
	> File Name: prize.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月09日 星期五 09时23分03秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int n;
    int temp, num;
    scanf("%d", &n);
    num = n;
    while(num >= 3)
    {
        temp = num % 3;
        num = num / 3; 
        n += num;
        num = num + temp;
    }
    printf("%d", n);
    return 0;
}
