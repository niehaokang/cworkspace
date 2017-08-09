/*************************************************************************
	> File Name: set.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月25日 星期二 15时36分24秒
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<set>
#define N 20
using namespace std;
int main()
{
    int i;
    srand(time(NULL));
    multiset< int,greater<int> > set;
    multiset< int, greater<int> >::iterator it;
    for( i = 0; i < N; i++ )
        set.insert(rand() % N);
    it = set.begin();
    for( i = 0; i < N; i++ )
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    cout << set.size() << endl;
    it = set.begin();
    for( i = 0; i < N; i++ )
    {
        cout << *it << " ";
        it++;
    }
    return 0;
}

