/*************************************************************************
	> File Name: string.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月13日 星期三 20时12分21秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s = "123401";
    cout << s.size() << endl;
    char *c = new char[20];
    s += '\0';
    s += 'a';
    strcpy(c, s.c_str());
    cout << strlen(c) << endl;
    cout << : << " " << c << endl;
    return 0;
}
