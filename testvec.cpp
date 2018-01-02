/*************************************************************************
	> File Name: testvec.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月14日 星期四 17时01分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
struct A{
    vector<int> a;
};
int main()
{
    A a;
    for( int i = 0; i < 15; i++ )
    {
        a.a.push_back(i);
        cout << a.a.capacity() << " " << sizeof(a) << endl;
    }
    return 0;
}
