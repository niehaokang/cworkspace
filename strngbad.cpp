/*************************************************************************
	> File Name: strngbad.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月20日 星期一 09时48分04秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include "strngbad.h"
using namespace std;

int StringBad::num_strings = 0;

StringBad::StringBad(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings ++;
    cout << num_strings << ": \"" << str << "\" object Created\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings ++;
    cout << num_strings << ";\"" << str << "\" default object Created\n";
}

StringBad::StringBad(const StringBad & st)
{
    num_strings ++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << num_strings << ": \"" << str << "\" object Created\n";
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}

