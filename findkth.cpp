/*************************************************************************
	> File Name: findkth.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月26日 星期六 16时25分45秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int i = 0;
    int k;
    int temp;
    vector<int> kthvec;
    while( i < 4 )
    {
        cin >> temp;
        kthvec.push_back(temp);
        ++i;
    }
    cin >> k;
    k = i - k;
    i = 0;
    sort( kthvec.begin(), kthvec.end() );
    vector<int>::iterator it;
    for( it = kthvec.begin(); i < k; ++it, ++i );
    cout << *it << endl;
    return 0;
}
