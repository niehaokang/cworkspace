/*************************************************************************
	> File Name: Power.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月18日 星期二 22时21分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Pow( double base, int exponent);

int main()
{
    double d = -8.99;
    int n = -3;
    printf("%f\n", Pow(d, n));
    printf("%f\n", pow(d, n));
    return 0;
}

double Pow( double base, int exponent)
{
    double result = 1;
    int e = exponent;
    int flag = 0;
    if( exponent < 0 )
    {
        if( fabs(base - 0 ) < 0.0000001)
        {
            printf("Bad input ...");
            exit(-1);
        }
        flag = 1;
        e = -exponent;
    }
    while( e )
    {
        if( e & 1  )
            result *= base;
        base *= base;
        e >>= 1;
    }
    if( flag )
        result = 1 / result;
    return result;
}
