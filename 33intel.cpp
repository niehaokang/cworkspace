/*************************************************************************
	> File Name: 33intel.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月14日 星期四 16时42分09秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

void remove_comments(char *txt);

int main()
{
    char str[] = "ab/*123*/c";
    remove_comments(str);
    cout << str << endl;
    return 0;
}

void remove_comments(char *txt)
{
    char *p = txt;
    char *q = txt;
    char *pp;
    while( *p != '\0' )
    {
        if( *p == '/' && *(p+1) == '*' )
        {
            pp = p + 2;
            while(*pp != '\0' && !( *pp == '*' && *(pp+1) == '/'))
                pp++;
            if( *pp == '\0' )
            {
                strcpy(q,p);
            }
            else
                p = pp + 2;
        }
        else
        {
            *q = *p;
            q++;
            p++;
        }
    }
}

