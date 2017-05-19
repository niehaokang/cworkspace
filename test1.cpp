/*************************************************************************
	> File Name: test1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月15日 星期三 16时29分43秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    char ch;
    int ct1, ct2;
    int x = 1;

    cout << !x << !!x << endl;

    ct1 = ct2 = 0;
    while((ch = cin.get()) != '$')
    {
        cout << ch;
        ct1 ++;
        if(ch == '$')
            ct2++;
        cout << ch;
    }
    cout <<"ct1 = " << ct1 <<"ct2 = " << ct2 << endl;
    return 0;
}
