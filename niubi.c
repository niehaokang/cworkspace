/*************************************************************************
	> File Name: niubi.c
	> Author: Datou_Nie
	> Mail:
	> Created Time: 2017年04月12日 星期三 13时28分37秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
    int i, j, count;
    int n;
    scanf("%d", &n);
    i = (int)sqrt(2 * n) - 1;

    count = (i * (i + 1) - 2) / 2;
    if( count + i + 1 < n )
    {
        i++;
        count += i;
    }
    i++;
    int a[i];

    a[0] = (i * (i - 5) + 8) / 2;

    j = 1;
    while(count + j < n)
    {
        a[j] = a[j-1] + 1;
        j++;
    }
    printf("%d\n", a[j-1]);
    return 0;
}
