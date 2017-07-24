/*************************************************************************
	> File Name: fournum.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月21日 星期五 22时32分27秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n1, n2, n3, n4;
    double a, b, c;
    cin >> n1 >> n2 >> n3 >> n4;
    if( (n1 + n3) % 2 != 0 || ( n3 - n1 ) % 2 != 0 || ( n4 - n2 ) % 2 != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    a = (n1 + n3)/2;
    b = (n3 - n1)/2;
    c = (n4 - n2)/2;
    if( n2 != b - c)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}
