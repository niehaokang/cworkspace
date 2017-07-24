/*************************************************************************
	> File Name: rev.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月21日 星期五 21时27分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

int rev( int n );

int main()
{
    int x, y;
    cin >> x >> y;
    cout << rev( rev(x) + rev(y) );
    return 0;
}

int rev( int n )
{
    int result = 0;
    int temp;
    while( n > 0 )
    {
        temp = n % 10;
        result = result * 10 + temp;
        n = n / 10;
    }
    return result;
}
