/*************************************************************************
	> File Name: shift_array.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月16日 星期日 13时17分12秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

void print_array( int *a , int length);

int shift_value( int *a, int left, int right );

void shift_array( int *a, int length, int shift );

int main()
{
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print_array(a, 10);
    shift_array( a, 10, 0 );
    print_array(a, 10);
    cout << shift_value( a, 0, 9 ) << endl;;
    return 0;
}

void print_array( int *a , int length)
{
    for( int i = 0; i < length; i++ )
        cout << a[i] << " ";
    cout << endl;
}

void shift_array( int *a, int length, int shift )
{
    int i;
    int b[length];
    memcpy(b, a, length * sizeof(int));
    for( i = 0; i < length; i++ )
        a[(i + shift) % length] = b[i];
}

int shift_value( int *a, int left, int right )
{
    int low = left;
    int high = right;
    int mid = left;
    while( a[low] > a[high] )
    {
        if( high - low == 1 )
        {
            mid = high;
            break;
        }
        mid = ( high + low ) / 2;
        if( a[mid] < a[right] )
            high = mid - 1;
        else
            low = mid;
    }
    return mid;
}
