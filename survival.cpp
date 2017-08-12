/*************************************************************************
	> File Name: survival.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月12日 星期六 15时54分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int x, f, d, p;
    int result;
    cin >> x >> f >> d >> p;
    result = ( d + p * f ) / ( p + x );
    cout << result << endl;
    return 0;
}
