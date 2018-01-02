/*************************************************************************
	> File Name: map.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月16日 星期六 13时25分02秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string, int> str_intmap;
    string str;
    int i = 0;
    while( cin >> str )
    {
        if( str_intmap.count(str) == 0)
        {
            str_intmap[str] = i++;
            cout << str << " " << str_intmap[str] << endl;
        }
    }
    return 0;
}

