/*************************************************************************
	> File Name: Mystring.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月12日 星期三 09时00分08秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
class Mystring{
private:
    char *str;
    int len;
public:
    Mystring(const char * pms);
    Mystring(const Mystring & rms);
    ~Mystring(void);
    Mystring & operator=(const Mystring & rms);
};

Mystring::Mystring(const char * pms)
{
    if(pms == NULL) 
        return;
    len = strlen(pms);
    str = new char[len+1];
    strcpy(str, pms);
}

Mystring::Mystring(const Mystring & rms)
{
    len = rms.len;
    str = new char[len+1];
    strcpy(str, rms.str);
}

Mystring::~Mystring(void)
{
    delete [] str;
}

/*
Mystring & Mystring::operator=(const Mystring & rms)
{
    if(this != &rms)
    {
        delete [] str;
        len = rms.len;
        str = new char[len+1];
        strcpy(str, rms.str);
    }
    return *this;
}
*/

Mystring & Mystring::operator=(const Mystring & rms)
{
    if(this != &rms)
    {
        char * temp = new char[rms.len+1];
        strcpy(temp, rms.str);
        delete [] str;
        len = rms.len;
        str = temp;
    }
    return *this;
}
