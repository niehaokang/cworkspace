/*************************************************************************
	> File Name: circle.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月18日 星期二 21时01分09秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
    int i, j;
    int n;
    int count = 0;
    scanf("%d", &n);
    for( i = 0; 2 * i * i <= n; i++ )
    {
        for( j = sqrt(n); 2 * j * j >= n; j-- )
            if( i * i + j * j == n )
        {
            if(i == 0)
                count += 4;
            else if(i == j)
                count += 4;
            else
                count += 8;
        }
    }
    printf("%d", count);
    return 0;
}
