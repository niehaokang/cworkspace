/*************************************************************************
	> File Name: encode.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月30日 19:38:48
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stack>
using namespace std;
void convertTo26( const char *intpu, char *output);
void convert10To26( const char *input, char *output);
int main()
{
    char s[] = "huawei";
    char p[100];
    char ss[] = "104680767";
//    convertTo26( s, p);
    convert10To26( ss, p);
    cout << p << endl;
    return 0;
}

void convert10To26( const char *input, char *output)
{
    int result = atoi( input);
    stack<char> s;
    int temp;
    while( result > 0)
    {
        temp = result % 26;
        s.push(temp - 1 + 'a');
        result = result / 26;
    }
    int i = 0;
    while( !s.empty())
    {
        output[i++] = s.top();
        s.pop();
    }
    cout << output << endl;
}

void convertTo26( const char *input, char *output)
{
    int len = strlen( input ); 
    int result = 0;
    int i = 0;
    while( i < len )
    {
        result = result * 26;
        result += (input[i] - 'a' + 1);
        ++i;
    }
    sprintf(output, "%d", result);
}
