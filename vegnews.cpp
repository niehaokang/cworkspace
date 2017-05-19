/*************************************************************************
	> File Name: vegnews.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月20日 星期一 10时08分27秒
 ************************************************************************/

#include<iostream>
#include "strngbad.h"
using namespace std;

void callme1(StringBad &);
void callme2(StringBad);

int main()
{
    StringBad headline1("Celery Stalks at Midnight");
    StringBad headline2("Lettue Prey");
    StringBad sports("Spinach Leaves Bow1 for Dollars");
    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "sports: " << sports << endl;
    callme1(headline1);
    cout << "headline1: " << headline1 << endl;
    callme2(headline2);
    cout << "headline2: " << headline2 << endl;
    cout << "Initialize one object to another: \n";
    StringBad sailor = sports;
    cout << "sailor: " << sailor << endl;
    cout << "assign one object to another: \n";
    StringBad knot;
    knot = headline1;
    cout << "knot: " << knot << endl;
    cout << "End of main()\n";
    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "StringBad passed by reference: \n";
    cout << "  \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value: \n";
    cout << "  \"" << sb << "\"\n";
}

