/*************************************************************************
	> File Name: gunshot.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月19日 星期二 20时30分11秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[] = { 9, 8, 5, 2 };
    int num = 4;
    int shot = 3;
    int carry = 2;
    int count  = 0;
    int temp = 0;
    sort( a, a + num, greater<int>() );
    while( true )
    {
        if(a[0] <= 0)
            break;
        ++count;
        a[0] -= shot;
        for( int i = 1; i < num; i++ )
        {
            if( a[i] <= 0 )
                break;
            a[i] -= carry;
        }
        temp = a[0];
        int j = 1;
        while( a[j] > temp && a[j] > 0 )
        {
            a[j-1] = a[j];
            j++;
        }
        a[j-1] = temp;
    }
    cout << count << endl;
    return 0;
}

