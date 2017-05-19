/*************************************************************************
	> File Name: apple.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月20日 星期四 11时22分14秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i, j;
    int temp;
    int n;
    scanf("%d", &n);
    int result = 1;
    for ( i = 1; ; i += n )
    {
        temp = i;
        for( j = 1; j < n; j++ )
        {
            temp = (temp - 1)/n * (n -1);
            if( temp % n == 1  )
                continue;
            else
                break;
        }
        if( j == n)
            break;
    }
    printf("%d\n", i);
    return 0;
}
