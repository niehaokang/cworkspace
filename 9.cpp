/*************************************************************************
	> File Name: 9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月22日 星期三 11时09分35秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int a[6][2] ={1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = a[1];
    int(*q)[2] = &a[1];
    cout << *++p << " " << q[0][0] << " " << q[1][2] << " " << q[0][4] << endl;
    return 0;
}