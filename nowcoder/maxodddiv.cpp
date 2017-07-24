/*************************************************************************
	> File Name: maxodddiv.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月21日 星期五 21时33分58秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    unsigned i, n;
    long temp, result = 0;
    cin >> n;
    for( i = n; i >= 1; i >>= 1 )
    {
        temp = ( i + 1 ) >> 1;
        result += temp * temp;
    }
    cout << result << endl;
    return 0;
}

