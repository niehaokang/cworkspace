/*************************************************************************
	> File Name: product.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月21日 星期一 19时14分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct product
{
    int l;
    int w;
};

bool compare(struct product a, struct product b)
{
    if( a.l == b.l )
        return (a.w < b.w);
    else
        return (a.l < b.l);
}

int main()
{
    int n;
    cin >> n;
    int min[n];
    int count = 0;
    memset( min, 0, n * sizeof(int) );
    vector<struct product> pro;
    for( int i = 0; i < n; i++ )
    {
        struct product *temp = new struct product;
        cin >> temp->l >> temp->w;
        pro.push_back(*temp);
    }
    sort( pro.begin(), pro.end(), compare );
    min[0] = pro[0].w;
    for( int i = 1; i < n; i++ )
    {
        int j = 0;
        while( j < n )
        {
            if(pro[i].w >= min[j])
            {
                min[j] = pro[i].w;
                break;
            }
            else
                j++;
        }
    }
    for( int i = 0; i < n; i++ )
        if( min[i] != 0 )
            count++;
    cout << count << endl;
    return 0;
}
