/*************************************************************************
	> File Name: ddctf.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月17日 星期三 20时23分29秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    int i;
    signed int v1;
    int v2;
    //for( i = -100; i < 100; i++ )
    //{
    char str[100] = {
        0x41,0x10,0x11,0x11,0x1b,0x0a,0x64,0x67,0x6a,0x68,0x62,0x68,0x6e,0x67,0x68,0x6b,
        0x62,0x3d,0x65,0x6a,0x6a,0x3d,0x68,0x04,0x05,0x08,0x03,0x02,0x02,0x55,0x08,0x5d,
        0x61,0x55,0x0a,0x5f,0x0d,0x5d,0x61,0x32,0x17,0x1d,0x19,0x1f,0x18,0x20,0x04,0x02,
        0x12,0x16,0x1e,0x54,0x20,0x13,0x14,0x00
    };
    v1 = 0;
    v2 = 73;
    while( v1 < 55 )
    {
        str[v1] -= 2;
        str[v1] ^= v2;
        ++v1;
        ++v2;
    }
        printf("\nFinal output is %s\n", &str[1]);
    //}
    return 0;
}

/*
int sub_2()
{
    return printf("This is a dummy function\n");
}

long long start()
{
    printf("Welcome\n");
    sub_2();
    return 0LL;
}
*/
