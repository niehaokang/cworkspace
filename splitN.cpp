/*************************************************************************
	> File Name: splitN.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月27日 星期三 14时54分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

int x[1024] = {0}, total = 0;

void splitN( int n, int m )
{
    int r, i, j;
    for( i = 1; i <= n; i++ )
    {
        if( i >= x[m-1] )
        {
            x[m] = i;
            r = n - i;
            if( r == 0 && m > 1 )
                total++;
            else
                splitN( r, m + 1 );
        }
        x[m] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    splitN( n, 1 );
    cout << total + 1 << endl;
}
