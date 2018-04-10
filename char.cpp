/*************************************************************************
	> File Name: char.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月10日 星期日 20时41分12秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[100009];
    char c;
    cin >> str;
    cin >> c;
    int len = strlen( str );
    int i = 0, j;
    while( str[j] != '\0' )
    {
        if(str[j] == c)
            j++;
        else
            str[i++] = str[j++];
    }
    str[i] = '\0';
    cout << str << endl;
    return 0;
}
