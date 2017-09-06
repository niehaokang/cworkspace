/*************************************************************************
	> File Name: maxsubstr.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月31日 20:24:43
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    int k;
    long total;
    while( cin >> n) 
    {
        int a[n];
        long x[n];
        int maxlen = 0;
        memset( x, 0, sizeof(long) * n);
        for( int i = 0; i < n; i++)
        {
            cin >> a[i];
            x[i] = x[i-1] + a[i];
        }
        cin >> k;
        if( x[n-1] % k == 0)
        {
            cout << n << endl;
            return 0;
        }
        else
        {
            for( int i = n - 1; i >= 0; --i)
            {
                for( int j = 0; j < i; j++)
                {
                    if( (x[i] - x[j]) % k == 0)
                    {
                        if( i - j > maxlen)
                            maxlen = i - j;
                    }
                }
            }
            cout << maxlen << endl;
        }
    }
    return 0;
}
