/*************************************************************************
	> File Name: packeg.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月28日 星期一 19时31分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d, e, f;
    int aa = 0, bb = 0;
    int count = 0;
    while( true )
    {
        cin >> a >> b >> c >> d >> e >> f;
        if( a == b && b == c && c == d && d == e && e == f && f == 0 )
            break;
        else
        {
            count += f;
            count += e;
            aa = e * 11;
            count += d;
            bb = d * 5;
            if( c % 4 )
            {
                count += ( c / 4 ) + 1;
                if( c % 4 == 1 )
                {
                    aa += 7;
                    bb += 5;
                }
                else if( c % 4 == 2 )
                {
                    aa += 6;
                    bb += 3;
                }
                else
                {
                    aa += 5;
                    bb += 1;
                }
            }
            else
                count += c / 4;
            if( b >= bb )
            {
                b -= bb;
                if( b % 9 )
                {
                    count += ( b / 9 ) + 1;
                    aa += ( 36 - (b % 9)* 4 );
                }
                else
                    count += b / 9;
            }
            else
            {
                bb -= b;
                aa += bb * 4;
            }
            if( a > aa )
            {
                a -= aa;
                if( a % 36 )
                    count += ( a / 9 ) + 1;
            }
            cout << count << endl;
        }
    }
    return 0;
}
