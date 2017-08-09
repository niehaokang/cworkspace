/*************************************************************************
	> File Name: evenstr.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月25日 星期二 19时18分58秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
bool isequal( char *a, char *b, int len);
int main()
{
    int i;
    char str[200];
    cin >> str;
    int len = strlen(str);
    int index = len / 2;
    for( i = len - 1; i >= 0; i -= 2)
    {
        --index;
        if( isequal( str, str + index, index) )
        {
            cout << 2 * index << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}

bool isequal( char *a, char *b, int len)
{
    if( a == NULL && b == NULL )
        return true;
    for( int i = 0; i < len; i++ )
    {
        if( a[i] != b[i] )
            return false;
    }
    return true;
}
