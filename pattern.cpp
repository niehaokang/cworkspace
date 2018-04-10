/*************************************************************************
	> File Name: pattern.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月08日 星期五 20时21分11秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[109];
    cin >> str;
    int len = strlen(str);
    int i = 1;
    char *p, *q;
    while( i < len  )
    {
        p = str;
        q = str + i;
        while( *q != '\0' )
        {
            if( *q == * p )
            {
                q++;
                p++;
            }
            else
                break;
        }
        if( *q == '\0' )
            break;
        i++;
    }
    strcpy(str + i, str);
    cout << str << endl;
    return 0;
}
