/*************************************************************************
	> File Name: sum.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月14日 星期四 09时06分45秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for( int i = 0; i < n; i++ )
        cin >> a[i];
    int dp[k+1];
    int count;
    memset(dp, 0, (k+ 1) * sizeof(int));
    dp[0] = 1;
    for(int i = 0; i < n; i++ )
    {
        for( int j = k; j >= 0; j-- )
            dp[j] = dp[j] || dp[j-a[i]];
        if( dp[k] != 0 )
            break;
    }

    if( dp[k] )
        cout << dp[k] << endl;
    else
        cout << "No" << endl;
    return 0;
}
