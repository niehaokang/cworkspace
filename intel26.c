/*************************************************************************
	> File Name: intel26.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月14日 星期四 15时32分18秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int a[5] = {1,2,3,4,5};
    int *ptr1 = (int*)(&a+1);
    printf("%d", ptr1[-1]);
    return 0;
}
