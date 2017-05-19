/*************************************************************************
	> File Name: str.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月23日 星期四 09时19分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

void str(char str[7])
{
    cout << sizeof(str) << endl;
    cout << sizeof(int *) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(double *) << endl;
}

int main()
{
    char s[10] = "niehao";
    str(s);
    return 0;
}
