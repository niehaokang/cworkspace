/*************************************************************************
	> File Name: Palindrome.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月25日 星期二 19时32分09秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[1009];
    cin >> s;
    char *p = s;
    int count = 0;
    int index[256];
    memset( index, 0, 256 * sizeof( int ) );
    while( *p != '\0' )
    {
        ++index[*p];
        ++p;
    }
    for( int i = 0; i < 256; i++ )
        if( index[i] % 2 == 1 )
            ++count;
    if( count == 0 )
        cout << 1 << endl;
    else
        cout << count << endl;
    return 0;
}
