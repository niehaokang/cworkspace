/*************************************************************************
	> File Name: move_circle.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月22日 星期六 13时35分46秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
    int r, x, y, x1, y1;
    scanf("%d %d %d %d %d", &r, &x, &y, &x1, &y1);
    double d = sqrt(pow( ( x - x1 ), 2 ) + pow( ( y - y1 ), 2 ));
    int steps = d / ( 2 * r );
    if( fmod(d, (2 * r)) )
        printf("%d", steps + 1);
    else
        printf("%d", steps);
    return 0;
}
