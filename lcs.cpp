/*************************************************************************
	> File Name: lcs.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月09日 星期六 16时14分27秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 105

int dp[N+1][N+1];

char str1[N],str2[N];

int LCSL(int len1,int len2)
{
    int i,j;
    int len = len1>len2?len1:len2;
    for(i=0;i<=len;i++)
    {
        dp[i][0]=0;
        dp[0][i]=0;
    }
    for(i=1;i<=len1;i++)
        for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]= dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
        }
    return dp[len1][len2];
}
int main()
{
    while(cin >> str1 >> str2)
    {
        int len1=strlen(str1);
        int len2=strlen(str2);
        cout <<LCSL(len1,len2)<<endl;
    }
    return 0;
}
