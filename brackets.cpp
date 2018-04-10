/*************************************************************************
	> File Name: brackets.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月11日 星期一 21时27分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

char str[1009];

void brackets( int n, int l, int r )
{
    int index = l + r;
    if( l == r && l == n )
    {
        cout << str << endl;
        return;
    }
    if( l < r || index >= 2 * n )
        return;
    str[index] = '(';
    brackets( n, l + 1, r );
    str[index] = ')';
    brackets( n, l, r + 1 );
}

int main()
{
    int n;
    cin >> n;
    brackets(n, 0, 0);
    return 0;
}
