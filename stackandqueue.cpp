/*************************************************************************
	> File Name: stackandqueue.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月14日 星期五 16时04分43秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<queue>
#include<cstdlib>
#define DATATYPE int
using namespace std;

class mystackqueue{
private:
    stack<DATATYPE> instack;
    stack<DATATYPE> outstack;
public:
    mystackqueue(){};
    mystackqueue(DATATYPE *a, int length);
    ~mystackqueue(){};
    void appendtail(const DATATYPE &element);
    DATATYPE deletehead();
};

class myqueuestack
{
private:
    queue<DATATYPE> queue1;
    queue<DATATYPE> queue2;
public:
    myqueuestack(){};
    ~myqueuestack(){};
    DATATYPE pop();
    void push( const DATATYPE & element );
};

class minstack 
{
private:
    int min_val;
    stack<int> stacknormal;
    stack<int> stackmin;
public:
    void push(int n);
    void pop();
    int min(); 
};

bool ispoporder( const int * in, const int * out, int length );

int main()
{
    /*
    DATATYPE a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    mystackqueue *queue = new mystackqueue(a, 10);
    mystackqueue queue;
    queue.appendtail( 10 );
    queue.appendtail( 10 );
    cout << queue.deletehead( ) << endl;;
    queue.appendtail( 9 );
    queue.appendtail( 8 );
    queue.appendtail( 7 );
    cout << queue.deletehead( ) << endl;;
    cout << queue.deletehead( ) << endl;;
    cout << queue.deletehead( ) << endl;;
    myqueuestack stack;
    stack.push(10);
    stack.push(9);
    cout << stack.pop() << endl;
    stack.push(8);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    */
    minstack ms;
    ms.push(10);
    ms.push(1);
    cout << ms.min() << endl;
    ms.pop();
    cout << ms.min() << endl;
    ms.push(11);
    cout << ms.min() << endl;
    int in[5] = {1, 2, 3, 4, 5};
    int out[5] = {4, 3, 2, 1, 5};
    cout << ispoporder( in, out, 5) << endl;
    return 0;
}

bool ispoporder( const int * in, const int * out, int length )
{
    if( in == NULL || out == NULL || length <= 0 )
        return false;
    const int * pus = in, *po = out;
    stack<int>tempstack;
    while( po - out < length )
    {
        while( tempstack.empty() || tempstack.top() != *po )
        {
            if( pus - in == length )
                break;
            tempstack.push(*pus);
            pus++;
        }
        if( tempstack.top() != *po )
            return false;
        tempstack.pop();
        po++;
    }
    if( tempstack.empty() )
        return true;
    else
        return false;
}

void minstack::push(int n)
{
    if( stacknormal.empty() )
    {
        min_val = n;
    }
    else
    {
        if( n < min_val )
            min_val = n;
    }
        stacknormal.push(n);
        stackmin.push(min_val);
}

void minstack::pop()
{
    if(stacknormal.empty())
    {
        cout << "stack is empty!" << endl;
        exit(-1);
    }
    stacknormal.pop();
    stackmin.pop();
    min_val = stackmin.top();
}

int minstack::min()
{
    return stackmin.top();
}

mystackqueue::mystackqueue(DATATYPE * a, int length)
{
    int i;
    for( i = 0; i < length; i++ )
        instack.push(a[i]);

}

void mystackqueue::appendtail(const DATATYPE &element)
{
    instack.push(element);
}

DATATYPE mystackqueue::deletehead()
{
    if(outstack.empty())
        while(!instack.empty())
        {
            outstack.push(instack.top());
            instack.pop();
        }
    if(outstack.empty())
    {
        cout << "queue is empty\n";
        return -1;
    }
    DATATYPE head = outstack.top();
    outstack.pop();
    return head;
}

void myqueuestack::push(const DATATYPE &element)
{
    if( !queue2.empty())
        queue2.push(element);
    else 
        queue1.push(element);
}

DATATYPE myqueuestack::pop()
{
    DATATYPE value = -1;
    if(!queue1.empty())
    {
        while( queue1.size() > 1 )
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        value = queue1.front();
        queue1.pop();
    }
    else if( !queue2.empty() )
    {
        while(queue2.size() > 1)
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
        value = queue2.front();
        queue2.pop();
    }
    else
        cout << "stack is empty\n" << endl;
    return value;
}
