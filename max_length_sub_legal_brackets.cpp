/*************************************************************************
	> File Name: max_length_sub_legal_brackets.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月29日 星期二 21时18分13秒
 ************************************************************************/

/*
* 秒针系统面试题之最长合法括号子串
* */
#include<iostream>
#include<stack>
#include<cstring>
#define max( a, b ) ( (a > b)?a:b )
using namespace std;

int max_length_sub_legal_brackets( const char * s );

int main()
{
    char p[] = "(())())((()()))";
    cout << max_length_sub_legal_brackets( p );
    return 0;
}

int max_length_sub_legal_brackets( const char * p )
{
    int maxlen = 0;
    int start = -1;
    stack<char> s;
    int len = strlen( p );
    for( int i = 0; i < len; ++i )
    {
        if( p[i] == ')' )               //if p[i] = ")"
        {
            //if stack is empty, than not legal, set start = i;
            //else pop top element of stack
                //if stack is empty, current length is (i - start)
                //else current length is ( i - s.top() )
            if( s.empty )
                start = i;
            else
            {
                s.pop();
                if( s.empty() )
                    maxlen = max( maxlen, i - start );
                else
                    maxlen = max( maxlen, i - s.top());
            }
        }
        else                            //push stack if p[i] = '('
            s.push(i);
    }
    return maxlen;
}
