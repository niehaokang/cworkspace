/*************************************************************************
	> File Name: queuestack.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月11日 星期一 10时00分14秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<exception>
using namespace std;
class queuestack
{
private:
    queue<int> queue1;
    queue<int> queue2;
public:
    void push(int val);
    int pop();
};

void queuestack::push(int val)
{
    queue1.push(val);
}

int queuestack::pop()
{
    int temp;
    if(queue1.empty())
    {
        cout << "stack is empty ...\n";
        return -1;
    }
    else
    {
        while( queue1.size() != 1 )
        {
            temp = queue1.front();
            queue1.pop();
            queue2.push(temp);
        }
        temp = queue1.front();
        queue1.pop();
        while( !queue2.empty() )
        {
            int t = queue2.front();
            queue2.pop();
            queue1.push(t);
        }
        return temp;
    }
}

int main()
{
    queuestack qs;
    qs.push(20);
    qs.push(10);
    cout << qs.pop() << endl;
    qs.push(9);
    qs.push(6);
    cout << qs.pop() << endl;
    return 0;
}
