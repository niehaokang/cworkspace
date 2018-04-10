/*************************************************************************
	> File Name: brackets.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月11日 星期一 10时30分26秒
 ************************************************************************/

#include <iostream>  
#define MAXN 1010  
using namespace std;  
  
char str[MAXN];  
  
void brackets(int n, int l, int r)  
{  
    if(l == r && l + r == 2*n)
    {  
        cout << str << endl;
        return;  
    }  
    if(l < r || l + r >= 2*n) return;  
    int index = l + r;  
    str[index] = '(';  
    brackets(n, l+1, r);  
    str[index] = ')';  
    brackets(n, l, r+1);  
}  
  
int main()  
{  
    int n;  
    while(cin >> n) {  
        brackets(n, 0, 0);  
    }  
    return 0;  
}  
