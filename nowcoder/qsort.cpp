/*************************************************************************
	> File Name: qsort.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月15日 星期六 17时37分29秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<set>
#define N (1 << 20)
using namespace std;

int randominrange(int start, int end);

int partition( int * a, int length, int start, int end );

int odd_partition( int * a, int length, int start, int end );

int odd_partition( int * a, int length, int start, int end, bool (*func)(int));

bool compare( int n );

bool negative( int n );

void swap(int & a, int & b);

void qsort( int *a, int length, int start, int end );

void qsort_classic( int *a, int left, int right );

void topk_qsort( int *num, int len, int k );

void topk_heapsort( int *num, int len, int k, multiset< int, greater<int> > &mset );

void print(int i)
{
    cout << i << " "; 
}

int sequencesearch( int *a, int length, int value );

int binarysearch( int *a, int length, int value );

bool compare( int a, int b )
{
    if( a < b )
        return true;
    else
        return false;
}

int main()
{
    int a[10] = {0, -1, 2, -3, 4, -5, 6, -7, 8, -9};
    int b[N];
    srand(time(NULL));
    for( int i = 0; i < N; i++ )
//        b[i] = i;
        b[i] = rand() % N;
/*
    sort(b, b + (N - 1), compare);
    qsort(b, N, 0, N - 1);
    qsort_classic(b, 0, N - 1);
        for_each(b, b + 19, print);
    cout << endl;
    odd_partition(a, 10, 0, 9);
    for_each(a, a + 10, print);
    cout << endl;
    odd_partition(a, 10, 0, 9, compare);
    for_each(a, a + 10, print);
    cout << endl;
    odd_partition(a, 10, 0, 9, negative);
    for_each(a, a + 10, print);
    cout << endl;
    cout << "find 10 in array b" << binarysearch(b, N, 10) << endl;
    cout << "find 10 in array b" << sequencesearch(b, N, 10) << endl;
    for( int i = 0; i < N >> 15; i++ )
        qsort( b, N, 0, N - 1 );
    for( int i = 0; i < 10; i++ )
        cout << b[i] << " ";
    cout << endl;
*/
    for( int i = 0; i < N >> 13; i++ )
        topk_qsort( b, N, 10 );
    for( int i = 0; i < 10; i++ )
        cout << b[i] << " ";
    cout << endl;
    multiset< int, greater<int> > mset;
    for( int i = 0; i < N >> 13; i++ )
        topk_heapsort( b, N, 10, mset );
    mset.clear();
    topk_heapsort( b, N, 10, mset );
    multiset< int, greater<int> > :: iterator it;
    for( it = mset.begin(); it != mset.end(); ++it )
        cout << *it << " ";
    return 0;
}

void topk_heapsort( int *num, int len, int k, multiset< int, greater<int> > &mset )
{
    if( num == NULL )
    {
        cout << "bad input...\n";
        return;
    }
    if( k < 1 || len < k )
        return;
    for( int i = 0; i < len; i++ )
    {
        if( mset.size() < k )
            mset.insert(num[i]);
        else
        {
            if( num[i] < *(mset.begin()) )
            {
                mset.erase(mset.begin());
                mset.insert(num[i]);
            }
        }
    }
}

void topk_qsort( int *num, int len, int k )
{
    if( num == NULL )
    {
        cout << "bad input...\n";
        return;
    }
    int start = 0;
    int end = len - 1;
    int index = partition( num, len, start, end);
    while( index != k - 1 )
    {
        if( index > k - 1 )
            end = index - 1;
        else
            start = index + 1;
        index = partition( num, len, start, end );
    }
    /*
    for( int i = 0; i < k; i++ )
        cout << num[i] << " ";
    cout << endl;
    */
}

int randominrange(int start, int end)
{
    srand(time(NULL));
    return start + rand() % (end - start);
}

void swap(int & a, int & b)
{
    int temp = a; 
    a = b;
    b = temp;
}

int partition( int * a, int length, int start, int end )
{
    if( a == NULL || length == 0 || start < 0 || end >= length )
    {
        cout << "bad input..." << endl;
        exit(-1);
    }
    int index = ( start + end )/ 2;
//    int index = randominrange(start, end);
    swap(a[index], a[end]);
    int small = start - 1;
    for( index = start; index < end; index++ ) 
    {
        if(a[index] < a[end])
        {
            ++small;
            if(small != index)
                swap(a[small], a[index]);
        }
    }
    ++small;
    swap(a[small], a[index]);
    return small;
}

bool compare( int n )
{
    return n & 1 == 1;
}

bool negative( int n )
{
    return n < 0;
}

int odd_partition( int * a, int length, int start, int end , bool (*func)(int))
{
    if( a == NULL || length == 0 || start < 0 || end >= length )
    {
        cout << "bad input..." << endl;
        exit(-1);
    }
    int index = ( start + end )/ 2;
//    int index = randominrange(start, end);
    swap(a[index], a[end]);
    int odd = start - 1;
    for( index = start; index < end; index++ ) 
    {
        if(func(a[index]))
        {
            ++odd;
            if(odd!= index)
                swap(a[odd], a[index]);
        }
    }
    ++odd;
    swap(a[odd], a[index]);
    return odd;
}

int odd_partition( int * a, int length, int start, int end )
{
    if( a == NULL || length == 0 || start < 0 || end >= length )
    {
        cout << "bad input..." << endl;
        exit(-1);
    }
    int index = ( start + end )/ 2;
//    int index = randominrange(start, end);
    swap(a[index], a[end]);
    int odd = start - 1;
    for( index = start; index < end; index++ ) 
    {
        if(a[index] % 2 == 1)
        {
            ++odd;
            if(odd!= index)
                swap(a[odd], a[index]);
        }
    }
    ++odd;
    swap(a[odd], a[index]);
    return odd;
}

void qsort( int *a, int length, int start, int end )
{
    if( a == NULL || start < 0 || end >= length)
    {
        cout << "bad input..." << endl;
        exit(-1);
    }
    if(length == 0 || start == end)
        return;
    int index = partition(a, length, start, end);
    if(index > start)
        qsort(a, length, start, index - 1);
    if(index < end)
        qsort(a, length, index + 1, end);
}

void qsort_classic( int *a, int left, int right )
{
    if( a == NULL )
    {
        cout << "bad input...\n";
        exit(-1);
    }
    if( left >= right )
        return;
    int i = left, j = right;
    int key = a[left];
    while( i < j )
    {
        while( i < j && key <= a[j] )
            j--;
        a[i] = a[j];
        while( i < j && key > a[i] )
            i++;
        a[j] = a[i];
    }
    a[i] = key;
    qsort_classic(a, left, i - 1);
    qsort_classic(a, i + 1, right);
}

int sequencesearch( int *a, int length, int value )
{
    for( int i = 0; i < length; i++ )
        if( a[i] == value )
            return i;
    return -1;
}

int binarysearch( int *a, int length, int value )
{
    int low = 0, high = length - 1;
    int mid;
    while( low < high )
    {
        mid  = (high + low) / 2;
        if( a[mid] == value )
            return mid;
        else if( a[mid] < value )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
