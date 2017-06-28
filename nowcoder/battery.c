/*************************************************************************
	> File Name: battery.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月09日 星期五 09时09分48秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
    int x0, x1, x2, x3, y0, y1, y2, y3;
    int R;
    int count = 0;
    scanf("%d %d %d %d %d %d %d %d %d", &R, &x1, &y1, &x2, &y2, &x3, &y3, &x0, &y0);
    if( pow( R, 2 ) >= pow( x1 - x0, 2 ) + pow(y1 - y0, 2) )
        count++;
    if( pow( R, 2 ) >= pow( x2 - x0, 2 ) + pow(y2 - y0, 2) )
        count++;
    if( pow( R, 2 ) >= pow( x3 - x0, 2 ) + pow(y3 - y0, 2) )
        count++;
    /*
    if( R * R >= (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) )
        count++;
    if( R * R >= (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0) )
        count++;
    if( R * R >= (x3 - x0) * (x3 - x0) + (y3 - y0) * (y3 - y0) )
        count++;
    */
    printf("%dX", count);
    return 0;
}
