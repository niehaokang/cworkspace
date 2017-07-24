/*************************************************************************
	> File Name: youya.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月25日 星期六 11时23分30秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
    int d;
    scanf("%d", &d);
    double j, k = (double) d;
    int count = 0;
    double r = sqrt(k);
    int i = floor(sqrt(k/2)) + 1;
    if( r - floor(r) < 0.0000001)
        count += 4;
    else if( sqrt(k/2) - i + 1 < 0.0000001 )
        count += 4;
    while( i * i < d)
    {
        j = sqrt( d - i * i);
        if( j - floor(j) < 0.0000001)
            count += 8;
        i++;
    }
    printf("%d\n", count);
    return 0;
}
