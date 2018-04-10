/*************************************************************************
	> File Name: reversestack.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月22日 星期五 14时14分05秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int getbottomstack( stack<int> & revstack );

void reversestack_with_recurison( stack<int> &revstack );

int main()
{
    stack<int> revstack;
    revstack.push(1);
    revstack.push(4);
    revstack.push(3);
    revstack.push(2);
    while( !revstack.empty() )
    {
        cout << revstack.top() << " ";
        revstack.pop();
    }
    /*
    reversestack_with_recurison(revstack);
    while( !revstack.empty() )
    {
        cout << revstack.top() << " ";
        revstack.pop();
    }
    */
    return 0;
}

int getbottomstack( stack<int> & revstack )
{
    int temp = revstack.top();
    revstack.pop();
    if( revstack.empty() )
        return temp;
    else
    {
        int result = getbottomstack(revstack);
        revstack.push(temp);
        return result;
    }
}

void reversestack_with_recurison( stack<int> &revstack )
{
    if( revstack.empty() )
        return;
    int temp = getbottomstack(revstack); 
    reversestack_with_recurison(revstack);
    revstack.push(temp);
}
