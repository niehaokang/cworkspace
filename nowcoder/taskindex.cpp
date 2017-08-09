/*************************************************************************
	> File Name: taskindex.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月25日 星期二 20时51分46秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define valid( n ) ( n >= 1 && n <= 1024 )
using namespace std;
int main()
{
    bool b = false;
    unsigned task[32];
    memset( task, 0, 32 * sizeof(int) );
    int set, get;
    cin >> set >> get;
    if( !valid( set ) || !valid( get ) )
    {
        cout << -1 << endl;
        return 0;
    }
    int setindex = (set - 1) / 32;
    int setbit = (set - 1) % 32;
    int getindex = (get- 1) / 32;
    int getbit = (get - 1) % 32;

    task[setindex] += pow( 2, setbit ); 

    unsigned temp = pow( 2, getbit );
    cout << temp << endl;
    cout << task[getindex] << endl;
    b =  task[getindex] & temp;

    cout << b << endl;
    return 0;
}
