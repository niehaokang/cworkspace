/*************************************************************************
	> File Name: stackqueue.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月11日 星期一 09时01分21秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
class stackqueue
{
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    void push( int val );
    int pop( );
};

void stackqueue::push(int val)
{
    stack1.push(val);
}

int stackqueue::pop()
{
    int temp;
    if( stack2.empty())
    {
        while( !stack1.empty() )
        {
            temp = stack1.top();
            stack2.push(temp);
            stack1.pop();
        }
    }
    if(stack2.empty())
    {
        cout << "queue is empty ..." << endl;
        return -1;
    }
    else
    {
        temp = stack2.top();
        stack2.pop();
    }
    return temp; 
}

int main()
{
    stackqueue sq;
    sq.push(10);
    cout << sq.pop() << endl;
    sq.push(20);
    sq.push(9);
    sq.push(11);
    cout << sq.pop() << endl;
    cout << sq.pop() << endl;
    cout << sq.pop() << endl;
    cout << sq.pop() << endl;
    return 0;
}
