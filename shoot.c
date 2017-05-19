/*************************************************************************
	> File Name: shoot.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月22日 星期六 15时16分18秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    int p, n;
    scanf("%d %d", &p, &n);
    int a[n];
    int index[p];
    memset(index, 0, sizeof(index));
    for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    for( i = 0; i < n; i++ )
    {
        int ind = a[i] % p;
        if(index[ind] == 1)
        {
            printf("%d", i + 1);
            return 0;
        }
        else
            index[ind] = 1;
    }
    printf("-1");
    return 0;
}
