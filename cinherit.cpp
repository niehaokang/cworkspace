/*************************************************************************
	> File Name: cinherit.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月21日 星期四 22时59分38秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct autocar
{
    int numofwheel;
    int getnumwheel(  )
    {
        return numofwheel;
    }
    int setnumwheel( int n  )
    {
        numofwheel = n;
    }
}

struct car
{
    struct autocar acar;
    int (*set)(int n);
    int (*get)(int n);
}

struct moto
{
    struct autocar acar;
    int (*set)(int n);
    int (*get)(int n);
}

int main()
{
    struct car ccar;
}
