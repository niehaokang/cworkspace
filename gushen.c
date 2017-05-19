/*************************************************************************
	> File Name: gushen.c
	> Author: Datou_Nie
	> Mail: 
	> Created Time: 2017年04月11日 星期二 10时19分08秒
 ************************************************************************/
#include<stdio.h>
#include<memory.h>
#include<math.h>
int main()
{
    int n;
    int i, j;
    int count;
    scanf("%d", &n);
    int a[(int)sqrt(2 * n)];
    int b[(int)sqrt(2 * n)];
    i = 3;
    count = 2;
    a[0] = 1;
    a[1] = 2;
    b[0] = 1;
    b[1] = 2;
    while( count < n )
    {
        for(j = 0; j < i - 1 && count < n; j++)
        {
            a[j] = b[j] + i - 3;
            b[j] = a[j];
            count++;
        }
        if(count < n)
        {
            a[j] = a[j - 1] + 1;
            b[j] = a[j];
            count++;
        }
        else
        {
            j--;
            break;
        }
        i++;
    }

    if( n == 1 )
        printf("%d\n", 1);
    else
        printf("%d\n", a[j]);

    return 0;
}
