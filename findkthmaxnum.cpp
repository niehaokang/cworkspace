/*************************************************************************
	> File Name: findkthmaxnum.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月26日 星期六 15时50分28秒
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;
int main()
{
    int i = 0;
    int k = 0;
    int len;
    int temp;
    multiset<int> kthset;
    while( cin >> temp )
    {
        kthset.insert(temp);
        ++i;
    }
    cin >> k;
    k = i - k;
    i = 0;
    multiset<int>::iterator it;
    for( it = kthset.begin(); i < k; ++it, ++i );
    cout << *it << endl;
    return 0;
}
