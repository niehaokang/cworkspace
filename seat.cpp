/*************************************************************************
	> File Name: seat.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月27日 星期三 14时42分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int n;
    while( cin >> n )
    {
        int result;
        if( n == 1 )
            result = 0;
        else if( n == 1 )
            result = 1;
        else
        {
            int a = 0, b = 1;
            for( int i = 3; i <= n; i++ )
            {
                result = ( i - 1) * ( b + a );
                a = b;
                b = result;
            }
        }
        cout << result << endl;
    }
}
