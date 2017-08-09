/*************************************************************************
	> File Name: geohash.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月25日 星期二 21时40分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char s[7];
    s[7] = '\0';
    int i = 0;
    int left = -90, right = 90;
    int mid;
    while( i < 6 )
    {
        mid = (left + right) / 2;
        if(mid <= n )
        {
            left = mid;
            s[i++] = '1';
        }
        else
        {
            right = mid;
            s[i++] = '0';
        }
    }
    cout << s << endl;
    return 0;
}
