/*************************************************************************
	> File Name: strngbad.h
	> Author: 
	> Mail: 
	> Created Time: 2017年03月20日 星期一 09时44分18秒
 ************************************************************************/

#ifndef _STRNGBAD_H
#define _STRNGBAD_H
#include<iostream>
class StringBad
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    StringBad(const char * s);
    StringBad(const StringBad &);
    StringBad();
    ~StringBad();
    friend std::ostream & operator<<(std::ostream & os,
                                     const StringBad & st);
};
#endif
