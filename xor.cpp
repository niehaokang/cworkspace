/*************************************************************************
	> File Name: xor.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月10日 星期日 15时51分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int n;
    int count;
    while( cin >> n )
    {
        int a[n];
        int temp = 0;
        count = 0;
        for( int i = 0; i < n; i++ )
            cin >> a[i];
        for( int i = 0; i < n; i++ )
        {
            if( a[i] == 0 )
            {
                ++count;
                temp = 0;
            }
            else if( a[i] == a[i-1] )
            {
                ++count;
                temp = 0;
            }
            else
            {
                temp ^= a[i];
                if( temp == 0 )
                    ++count;
            }
        }
        cout << count << endl;
    }
    return 0;
}
