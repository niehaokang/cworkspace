/*************************************************************************
	> File Name: numberof1between1andn.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月26日 星期三 15时21分57秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int numberof1between1andn( int num );

int main()
{
    int n;
    cin >> n;
    cout << numberof1between1andn( n );
    return 0;
}

int numberof1between1andn( int num )
{
    if( num <= 0 )
        return 0;
    if( num < 10 )
        return 1;
    int temp = num;
    int bits = 0;
    int result = 0;
    while( temp >= 10 )
    {
        ++bits;
        temp = temp / 10;
    }
    int last = num % (int)pow( 10, bits );
    if( temp > 1 )
        result += pow( 10, bits ) + 1;
    else
        result += last + 1;
    if( bits != 0 )
        result += temp * bits * pow( 10, bits - 1 );
    result += numberof1between1andn( last);
    return result;
}
