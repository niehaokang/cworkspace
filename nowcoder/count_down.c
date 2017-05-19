/*************************************************************************
	> File Name: count_down.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月20日 星期四 13时10分06秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i;
    int flag;
    int d, m, y;
    int count = 0;
    scanf("%d-%d-%d", &y, &m, &d);
    if( y == 2015 )
    {
        switch( m )
        {
            case 10:
            count += d - 18;
            break;
            case 11:
            count += d + 31 - 18;
            break;
            case 12:
            count += d + 61 - 18;
        }
        printf("%d\n", count);
        return 0;
    }
    for( i = 2016; i < y; i++ )
    {
        if( i % 100 == 0)
        {
            if( i % 400 == 0)
                count += 366;
            else
                count += 365;
        }
        else if( i % 4 == 0 )
            count += 366;
        else
            count += 365;
    }
    if( y % 100 == 0 )
    {
        if( y % 400 == 0 )
            flag = 1;
    }
    else if ( y % 4 == 0 )
        flag = 1;
    switch( m )
    {
        case 1:
        count += d + 74;
        break;
        case 2:
        count += d + 74 + 31;
        break;
        case 3:
        count += d + 74 + 31 + 28;
        break;
        case 4:
        count += d + 74 + 31 + 28 + 31;
        break;
        case 5:
        count += d + 74 + 31 + 28 + 31 + 30;
        break;
        case 6:
        count += d + 74 + 31 + 28 + 31 + 30 + 31;
        break;
        case 7:
        count += d + 74 + 31 + 28 + 31 + 30 + 31 + 30;
        break;
        case 8:
        count += d + 74 + 31 + 28 + 31 + 30 + 31 + 30 + 31;
        break;
        case 9:
        count += d + 74 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
        break;
        case 10:
        count += d + 74 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        break;
        case 11:
        count += d + 74 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        break;
        case 12:
        count += d + 74 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        break;
    }
    if( flag == 1 && m > 2 )
        count += 1;
    printf("%d", count);
    return 0;
}
