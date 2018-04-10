/*************************************************************************
	> File Name: crazynum.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月08日 星期五 19时36分04秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    unsigned long n;
    cin >> n;
    int num = (int)sqrt( 2 * n);
    if( num + pow(num,2) > 2 * n )
        cout << num;
    return 0;
}
