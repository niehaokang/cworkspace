/*************************************************************************
	> File Name: privatevirtual.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月28日 星期一 10时55分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Base{
    int i;
private:
    virtual void fun() { cout << "Base fun" << endl; }
    virtual void nie() = 0;
    friend int main();
};

class Derived: public Base {
public:
    void fun() { cout << "Derived fun" << endl; }
    void nie() { cout << "My name is niehaokang\n" << endl; }
};
int main()
{
    Base *ptr = new Derived;
    cout << sizeof( *ptr ) << endl;
    cout << ptr << endl;
    cout << &(ptr->i) << endl;;
    return 0;
}
