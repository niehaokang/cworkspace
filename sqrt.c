/*************************************************************************
	> File Name: sqrt.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月22日 星期二 15时51分00秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
    int first, num;
    while( scanf("%d %d", &first, &num) != EOF )
    {
        double result = (double)first, temp;
        temp = sqrt( first );
        int i = 1;
        while( temp > 0.0000001 && i < num)
        {
            result += temp;
            i++;
            temp = sqrt(temp);
        }
        printf("%.2lf ", result);
    }
    return 0;
}
