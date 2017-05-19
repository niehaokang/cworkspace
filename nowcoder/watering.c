/*************************************************************************
	> File Name: watering.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月24日 星期一 13时14分17秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main()
{
    int i, j;
    int n;
    float temp;
    float s = 0;
    scanf("%d", &n);
    float r[n];
    for( i = 0; i < n; i++ )
        scanf("%f", &r[i]);
    for( i = 0; i < n; i++ )
        for( j = 0; j < n - i - 1; j++ )
            if( r[j] < r[j+1] )
            {
                temp = r[j];
                r[j] = r[j+1];
                r[j+1] = temp;
            }
    for( i = 0; i < n, s < 20; i++ )
        s += 2 * sqrt( pow( r[i], 2 ) - 1 );
    printf("%d\n", i);
    return 0;
}
