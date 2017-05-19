/*************************************************************************
	> File Name: apple_pow.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月20日 星期四 11时53分07秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (int)pow(n, n) - n + 1);
    return 0;
}
