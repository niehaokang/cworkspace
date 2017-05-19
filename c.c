/*************************************************************************
	> File Name: c.c
	> Author: Datou_Nie
	> Mail: 
	> Created Time: 2017年04月09日 星期日 21时35分35秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#define q(w, e) (a[w][0] >= a[e][0] && a[w][0] <= a[e][1])
int main()
{
    int i, j, k;
    int n;
    int hint_max = 0;
    int temp = 0;
    scanf("%d", &n);
    int a[n][2];

    for( i = 0; i < n; i++ )
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
        a[i][1] += a[i][0];
    }

    for( i = 0; i < n; i++ )
        for( j = i + 1; j < n; j++ )
        {
            for( k = 0; k < n; k++ )
                if(q(i, k) || q(j, k))
                    temp++;
            if(temp > hint_max)
                hint_max = temp;
            temp = 0;
        }

    printf("%d", hint_max);
    return 0;
}
#if 0
#include<stdio.h>
#include<string.h>
#define q(w, e) (a[e]<=a[w]&&b[e]>=a[w])

int a[205],b[205];
int n;

int main()
{ 
    int ans=0;
    int temp;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        b[i] += a[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            for(int k = 1; k <= n; k++)
                if(q(i,k)||q(j,k))
                    temp++;
            if(temp > ans)
               ans = temp;
            temp = 0;
        }

    printf("%d\n",ans); 
    return 0;
}
#endif
