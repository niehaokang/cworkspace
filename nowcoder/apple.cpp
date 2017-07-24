/*************************************************************************
	> File Name: apple.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月21日 星期五 22时21分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

int apple( int n );

int main()
{
    int n;
    cin >> n;
    cout << apple( n ) << endl;
    return 0;
}

int apple( int n )
{
    if( n < 6 || n == 10 || n % 2 == 1)
        return -1;
    else
    {
        if( n % 8 == 0 )
            return n / 8;
        else
            return n / 8 + 1;
    }
}
