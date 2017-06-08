/*************************************************************************
	> File Name: hash.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月22日 星期一 17时35分13秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define N 2654404609
int main()
{
    int pid_1 = 2890;
    int pid_2 = 29384;
    printf("hash(pid_1) = %d\n", (int)(pid_1 * N) / (int)pow( 2, 21 ));
    printf("hash(pid_1) = %d\n", (int)(pid_2 * N) / (int)pow( 2, 21 ));
    return 0;
}
