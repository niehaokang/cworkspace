/*************************************************************************
	> File Name: placenew1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月20日 星期一 21时04分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<string>
#include<new>
const int BUF = 512;

class JustTesting
{
private:
    string words;
    int number;
public:
    JustTesting(const string & s = "Just Testing", int n = 0)
    {
        words = s;
        number = n;
        cout << words << " constructed\n";
    }
    ~JustTesting()
    {
        cout << words << " destroyed\n";
    }
    void Show()
    {
        cout << words << ", " << number << endl;
    }
};

int main()
{
    char * buffer = new char[BUF];

    JustTesting *pc1, *pc2;
    pc1 = new (buffer) JustTesting;
    pc2 = new JustTesting("heap1", 20);

    cout << "memory block address:\n" << "buffer: " << (void *)buffer << " heap: " << pc2 << endl;
    cout << "memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();
    
    JustTesting *pc3, *pc4;
    pc3 = new (buffer + sizeof(JustTesting))JustTesting("Better Idea", 6);
    pc4 = new JustTesting("Heap2", 10);

    cout << "memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;
    delete pc4;
    pc3->~JustTesting();
    pc1->~JustTesting();
    delete [] buffer;
    cout << "Done\n";
    return 0;
}
