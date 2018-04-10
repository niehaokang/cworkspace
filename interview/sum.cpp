/*************************************************************************
	> File Name: sum.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月20日 星期三 15时54分57秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int sum;
    int n;
    cin >> n;
    while( n >= 1 )
        sum += n--;
    cout << sum << endl;
    return 0;
}
