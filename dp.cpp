/*************************************************************************
	> File Name: dp.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月27日 星期日 20时27分46秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int m, n;
    int i, j;
    cin >> m >> n;
    int a[m][n];
    int b[m][n];
    int c[m][n];
    memset( c, 0xff, sizeof( c ) );
    for( i = 0; i < m; i++ )
        for( j = 0; j < n; j++ )
            cin >> a[i][j];
    b[0][0] = a[0][0];
    for( i = 1; i < m; i++ )
        b[i][0] = b[i-1][0] + a[i][0];
    for( j = 1; j < n; j++ )
        b[0][j] = b[0][j-1] + a[0][j];
    for( i = 1; i < m; i++ )
    {
        for( j = 1; j < n; j++ )
        {
            if( b[i-1][j] > b[i][j-1] )
                b[i][j] = b[i-1][j] + a[i][j];
            else
                b[i][j] = b[i][j-1] + a[i][j];
        }
    }
    c[0][0] = b[0][0];
    for( i = 1; i < m; i++ )
    {
        if( b[i][0] > c[i-1][0] )
            c[i][0] = c[i-1][0];
        else
            c[i][0] = b[i][0];
    }
    for( j = 1; j < n; j++ )
    {
        if( b[0][j] > c[0][j-1] )
            c[0][j] = c[0][j-1];
        else
            c[0][j] = b[0][j];
    }
    for( i = 1; i < m; i++ )
    {
        for( j = 1; j < n; j++ )
        {
            if( c[i-1][j] > c[i][j-1] )
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
        }
    }
    cout << 1 - c[m-1][n-1] << endl;
    return 0;
}

