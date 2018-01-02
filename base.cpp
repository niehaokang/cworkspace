/*************************************************************************
	> File Name: base.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月17日 星期日 10时09分09秒
 ************************************************************************/

#include<iostream>
using namespace std;
class base
{
public:
    base(int i)
    {
        cout << i;
    }
};
class base1:virtual public base
{
public:
    base1(int i, int j = 0):base(j)
    {
        cout << i;
    }
};
class base2:virtual public base
{
public:
    base2(int i, int j = 0):base(j)
    {
        cout << i;
    }
};
class mm:public base2, public base1
{
private:
    base2 mem2;
    base1 mem1;
public:
    mm( int a, int b, int c, int d ):mem1(a), mem2(b),base1(c), base2(d), base(a)
    {
        cout << b;
    }
};

int main()
{
    mm obj(1, 2, 3, 4);
    return 0;
}
