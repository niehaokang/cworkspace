/*************************************************************************
	> File Name: mergesort.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月15日 星期六 20时19分33秒
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N (1 << 20)
using namespace std;

void merge(int *a, int start, int mid, int end, int * temp);

void mergesort(int * a, int start, int end, int * temp);

void print( int i);

bool compare( int a, int b)
{
    if( a < b )
        return true;
    else
        return false;
}

int main()
{
    int a[N];
    srand(time(NULL));
    for( int i = 0; i < N; i++ )
        a[i] = rand() % N;
    int temp[N];
//    mergesort(a, 0, N - 1, temp);
//    sort(a, a + N - 1, compare);
//    for_each(a, a + N, print);
    return 0;
}

void print(int i)
{
    cout << i << " ";
}

void merge(int *a, int start, int mid, int end, int * temp)
{
    int i = start, j = mid + 1;
    int k = 0;
    while( i <= mid && j <= end)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while( i <= mid )
        temp[k++] = a[i++];
    while( j <= end )
        temp[k++] = a[j++];
    memcpy(a + start, temp, k * sizeof(int));
//    for( i = 0; i < k; i++ )
//        a[start + i] = temp[i];
}

void mergesort(int * a, int start, int end, int * temp)
{
    if(start < end)
    {
        int mid = ( start + end ) / 2;
        mergesort( a, start, mid, temp );
        mergesort( a, mid + 1, end, temp );
        merge( a, start, mid, end, temp );
    }
}
