/*************************************************************************
	> File Name: push-up.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月08日 星期四 20时18分14秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);
    int num = 1;
    int round[n];
    memset(round, 0, n * sizeof(int));
    for( i = 0; i < (t - 1) * n; i++ )
    {
        round[i % n] += num;
//        printf("num[%d] = %d\n", i % n, round[i % n]);
        num = (num + i + 1) % k;
//        printf("num = %d\n", num);
    }
    round[0] += num % k;
    printf("%d", round[0]);
    return 0;
}
