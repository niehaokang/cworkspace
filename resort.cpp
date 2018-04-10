/*************************************************************************
	> File Name: resort.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月09日 星期六 15时35分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while( t > 0 )
    {
        int n;
        cin >> n;
        int a[n];
        for( int i = 0; i < n; i++ )
            cin >> a[i];
        int mul, mul_2 = 0, mul_4 = 0;
        for( int i = 0; i < n; i++ )
        {
            if( a[i] % 4 == 0 )
                ++mul_4;
            else if( a[i] % 2 == 0 )
                ++mul_2;
        }
        mul = n - mul_2 - mul_4;
        if(  mul_4 >= mul )
            cout << "Yes" << endl;
        else if ( mul_4 + 1 == mul && mul_2 == 1 )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        t--;
    }
    return 0;
}
