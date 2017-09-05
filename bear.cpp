/*************************************************************************
	> File Name: bear.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月 2日 15:05:29
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Bear
{
    int num;
    int battle;
    int hunger;
}Bear;

bool compare_energe(const int a, const int b)
{
    return a > b;
}

bool compare_bear( const struct Bear &a, const struct Bear &b)
{
    return a.battle > b.battle;
}

bool compare_bearnum( const struct Bear &a, const struct Bear &b)
{
    return a.num < b.num;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int energe[m];
    int index[m];
    memset(index, 0, sizeof(int) * m);
    struct Bear bear[n];
    for( int i = 0; i < m; i++)
        cin >> energe[i];
    for( int i = 0; i < n; i++)
    {
        cin >> bear[i].battle >> bear[i].hunger;
        bear[i].num = i;
    }
    sort( energe, energe + m, compare_energe);
    sort( bear, bear + n, compare_bear); 
    /*
    for( int i = 0; i < m; i++)
        cout << energe[i] << endl;
    for( int i = 0; i < n; i++)
        cout << bear[i].battle << " " << bear[i].hunger << endl;
    */
    for( int i = 0; i < n; ++i) 
    {
        for( int j = 0; j < m; j++)
        {
            if( bear[i].hunger >= 0 && energe[j] <= bear[i].hunger && index[j] == 0)
            {
                bear[i].hunger -= energe[j];
                index[j] = 1;
            }
        }
    }
    sort( bear, bear + n, compare_bearnum);
    for( int i = 0; i < n; i++)
        cout << bear[i].hunger << endl;
    return 0;
}
