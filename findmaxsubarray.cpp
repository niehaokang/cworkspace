/*************************************************************************
	> File Name: findmaxsubarray.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月26日 星期六 15时40分34秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int temp;
    int greastsum = 0x80000000;
    int cursum = 0;
    while( cin >> temp )
    {
        if( cursum = 0 )
            cursum = temp;
        else
            cursum += temp;
        if( cursum > greastsum )
            greastsum = cursum;
    }
    cout << greastsum << endl;
    return 0;
}
