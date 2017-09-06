/*************************************************************************
	> File Name: dp.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月21日 星期一 20时35分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>  
#include<cstring>  
#define min(a,b) ((a)<(b)?(a):(b))  
#define max(a,b) ((a)>(b)?(a):(b))  
using namespace std;
  
long a[10010];  
long f[10010][101];  
 
int main()  
{  
    long n; 
    long m;  
    long k;  
    cin >> n >> m >> k;
    for (long i=1;i<n+1;i++)  
        cin >> a[i];
    memset( f, 0x0, sizeof(f) );
    for (long i=1;i<n+1;i++)  
    {  
        f[i][1] = max(f[i-1][1],a[i]);  
    }  
    for (long i=k;i<n+1;i++)  
    {  
        for (long j=2;j<m+1;j++)  
        {  
            f[i][j] = max(f[i][j],f[i-1][j]);  
            if (i >= k)  
                f[i][j] = max(f[i][j],f[i-k][j-1]+a[i]);  
        }  
    }  
    printf("%ld",f[n][m]);  
    return 0;  
}  
