/*************************************************************************
	> File Name: paimai.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月12日 星期三 19时04分25秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define maxn 1009
int a[maxn];
int main(){
        int n, m, ans=0, a0;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=m; i++) scanf("%d", &a[i]);
        sort(a+1, a+1+m);
        for(int i=1; i<=m; i++) if (ans < a[i]*min(n,m-i+1))
            ans=a[i]*min(n,m-i+1), a0=a[i];
        printf("%d\n", a0);
        return 0;

}
