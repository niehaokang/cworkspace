/*************************************************************************
	> File Name: cc.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月09日 星期日 22时43分11秒
 ************************************************************************/

#include<cstdio>
#include<cstring>

int a[205],b[205];
int n;

bool q(int w,int e)
{
    return a[e]<=a[w]&&b[e]>=a[w];
}

int s(int w,int e)
{
    int re=0;
    for(int i=1;i<=n;i++)
        if(q(w,i)||q(e,i))
            re++;
    return re;
}

void work()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int l;
        scanf("%d %d",&a[i],&l);
        b[i]=a[i]+l;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int k=s(i,j);
            if(k>ans)
                ans=k;
        }
    printf("%d\n",ans); 
} 

int main()
{ 
    work(); 
    return 0;
}
