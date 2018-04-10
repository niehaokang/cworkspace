/*************************************************************************
	> File Name: ReverseStack.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月22日 星期五 18时42分51秒
 ************************************************************************/

#include<iostream>
#include <stack>
using namespace std;

int lowValue(stack<int> &s){
    int t=s.top();
    s.pop();
    if(s.empty()){
        return t;
    }
    int aim=lowValue(s);
    s.push(aim);
    return t;
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int t=lowValue(s);
    reverse(s);
    s.push(t);
}

int main(){
    stack<int> s;
    int a[]={2,3,4,8,10};
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        s.push(a[i]);
    }
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
