/*************************************************************************
	> File Name: set.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月25日 星期二 15时36分24秒
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<set>
#define N 10 
using namespace std;
int main()
{
    int i;
    srand(time(NULL));
    set< int, greater<int> > s;
    set< int, greater<int> >::iterator it;
    for( i = 0; i < N; i++ )
        s.insert(rand() % N);
    cout << s.size() << endl;
    for( it = s.begin(); it != s.end(); ++it )
        cout << *it << " ";
    cout << endl;
    return 0;
}

