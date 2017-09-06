/*************************************************************************
	> File Name: narcissus.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月22日 星期二 16时02分11秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
    int m, n;
    int count = 0;
    while( scanf("%d %d", &m, &n) != EOF )
    {
        int a, b, c;
        for( int i = m; i <= n; i++ )
        {
            a = i / 100;
            b = i % 100 / 10;
            c = i % 10;
            if( pow(a, 3) + pow(b, 3) + pow(c, 3) == i )
            {
                ++count;
                printf("%d ", i);
            }
        }
        if( count == 0 )
            printf("no ");
    }
    return 0;
}
