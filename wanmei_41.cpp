/*************************************************************************
	> File Name: wanmei_41.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月23日 星期三 17时40分48秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int i, j, k = 0;
    int meng = 0, boos = 0;
    int head_diff, tail_diff;
    int n;
    cin >> n;
    int a[n];
    for( i = 0; i < n; i++ )
        cin >> a[i];
    i = 0; j = n - 1;
    while( i <= j )
    {
        head_diff = a[i] - a[i+1];
        tail_diff = a[j] - a[j-1];
        if( head_diff > tail_diff )
        {
            if( k & 1 )
                boos += a[i];
            else
                meng += a[i];
            ++i;
        }
        else
        {
            if( k & 1 )
                boos += a[j];
            else
                meng += a[j];
            --j;
        }
        ++k;
    }
    cout << meng << " " << boos << endl;
    return 0;
}
