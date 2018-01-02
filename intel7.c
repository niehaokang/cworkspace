/*************************************************************************
	> File Name: intel7.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月14日 星期四 15时04分37秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int a[5] = {1,2,3,4,5};
    printf("%x", *(int*)((int)a + 1));
    return 0;
}
