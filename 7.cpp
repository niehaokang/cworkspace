/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月22日 星期三 10时41分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    signed char c1 = -1;
    int i1 = (int)c1;
    unsigned char c2 = -1;
    int i2 = (int)c2;
    int i3 = int(3 * 1.0/2 * 3);
    cout << i1 << " " << i2 << " " << i3 << endl;
    cout << int(4.5) << int(4.9) << endl;
    return 0;
}
