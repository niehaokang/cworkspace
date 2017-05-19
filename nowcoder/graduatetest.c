/*************************************************************************
	> File Name: graduatetest.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月21日 星期五 11时01分07秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i;
    int n;
    scanf("%d", &n);
    int a[n][4];
    for( i = 0; i < n; i++ )
        scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    for( i = 0; i < n; i++ )
    {
        if( a[i][0] < 60 || a[i][1] < 60 || a[i][2] < 90 || a[i][3] < 90 )
            printf("Fail\n");
        else if ( a[i][0] + a[i][1] + a[i][2] + a[i][3] < 310 )
            printf("Fail\n");
        else if ( a[i][0] + a[i][1] + a[i][2] + a[i][3] < 350 )
            printf("Zifei\n");
        else
            printf("Gongfei\n");
    }
    return 0;
}
