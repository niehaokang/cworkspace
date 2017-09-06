/*************************************************************************
	> File Name: coordinate.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月21日 星期一 19时14分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct coordinate
{
    int x;
    int y;
};

bool compare(struct coordinate a, struct coordinate b)
{
    if( a.x == b.x )
        return (a.y < b.y);
    else
        return (a.x < b.x);
}

int main()
{
    int n;
    cin >> n;
    int min[n][2];
    int count = 0;
    memset( min, 0, 2 * n * sizeof(int) );
    struct coordinate pro[n];
    for( int i = 0; i < n; i++ )
        cin >> pro[i].x >> pro[i].y;
    sort( pro, pro + n, compare );
    for( int i = 1; i < n; i++ )
    {
        int j = 0;
        while( j < n )
        {
            if(pro[i].y >= min[j][1])
            {
                min[j][0] = pro[i].x;
                min[j][1] = pro[i].y;
                break;
            }
            else
                j++;
        }
    }
    for( int i = 0; i < n; i++ )
        if( min[i][0] != 0 )
            count++;
    struct coordinate set_big[count];
    for( int i = 0; i < count; i++ )
    {
        set_big[i].x = min[i][0];
        set_big[i].y = min[i][1];
    }
    sort( set_big, set_big + count, compare);
    for(int i = 0; i < count; i++)
        cout << set_big[i].x << " " << set_big[i].y << endl;
    return 0;
}
