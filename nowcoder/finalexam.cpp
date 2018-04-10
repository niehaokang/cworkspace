/*************************************************************************
	> File Name: finalexam.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月14日 星期四 10时02分26秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n, m;
    while( cin >> n >> m )
    {
        char a[n][m];
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ )
                cin >> a[i][j];
        int c[m];
        memset(c, 0, m * sizeof(int));
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( a[i][j] == '.' )
                    c[j]++;
            }
        }
        int odd = 0;
        int even = 0;
        for( int i = 0; i < m; i++ )
        {
            if( i & 1 )
                even += c[i];
            else
                odd += c[i];
        }
        int max = odd>even?odd:even;
        cout << max << endl;
    }
}
