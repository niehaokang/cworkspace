/*************************************************************************
	> File Name: pickapple.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月19日 星期六 19时19分02秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int i;
    int count = 0;
    int a[10];
    int h;
    for( i = 0; i < 10; i++ )
        cin >> a[i];
    cin >> h;
    h += 30;
    for( i = 0; i < 10; i++ )
        if( a[i] <= h  )
            count++;
    cout << count;
    return 0;
}
