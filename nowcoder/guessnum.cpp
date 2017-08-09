/*************************************************************************
	> File Name: guessnum.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月25日 星期二 19时55分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool isprime( int n );

int main()
{
    int n;
    int result = 1;
    cin >> n;
    for( int i = 2; i <= n; i++ )
    {
        if( isprime( i ) )
            result = result * 2;
        if( (i & ( i - 1 )) == 0 )
            result = result * 3 / 2;
    }
    cout << result << endl;
    return 0;
}

bool isprime( int n )
{
    int i;
    for( i = 2; i * i <= n; i++ )
        if( n % i == 0 )
            return false;
    return true;
}
