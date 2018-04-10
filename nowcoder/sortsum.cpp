/*************************************************************************
	> File Name: sum.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月14日 星期四 09时06分45秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

bool sumarray( int *a, int len, int sum, vector<int> &vec )
{
    int count;
    for( int i = 0; i < vec.size(); i++ )
        count += vec[i];
    if( count == sum )
        return true;

}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for( int i = 0; i < n; i++ )
        cin >> a[i];
    sort( a, a+n );
    vector<int> vec;
    return 0;
}
