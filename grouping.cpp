/*************************************************************************
	> File Name: grouping.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月19日 星期六 19时26分38秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    cin >> a[0];
    for( int i = 1; i < n; i++ )
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    sort( a, a + n );
    int q;
    cin >> q; 
    int b[q];
    for( int i = 0; i < q; i++ )
        cin >> b[i];
    for( int i = 0; i < q; i++ )
    {
        int left = 0, right = n - 1;
        while( left < right )
        {
            int mid = ( left + right ) / 2;
            if( a[mid] < b[i] )
            {
                if( a[mid + 1] >= b[i] )
                {
                    cout << mid + 2 << endl;
                    break;
                }
                else
                    left = mid;
            }
            else if( a[mid] > b[i] )
                right = mid;
            else
            {
                cout << mid + 1 << endl;
                break;
            }
        }
        if( right == left )
            cout << right + 1 << endl;
    }
    return 0;
}
