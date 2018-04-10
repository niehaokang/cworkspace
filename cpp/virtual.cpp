/*************************************************************************
	> File Name: virtual.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月13日 星期三 17时18分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
class base
{
public:
void test()
    {
        fun();
    }
private:
    virtual void fun( )
    {
        cout << "print from base ..." << endl;
    }
};

class derive : public base
{
private:
    void fun()
    {
        cout << "print from derive ..." << endl;
    }
};

int main()
{
    base *b = new derive();
    derive bb;
    bb.test();
    //b->fun();
    return 0;
}
