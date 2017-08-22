/*************************************************************************
	> File Name: qsort.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月07日 星期三 09时28分03秒
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 20

typedef struct node
{
    int a;
    int b;
}node;

int compare( const void *a, const void *b );

int partition( int *a, int left, int right );

void quicksort( int * a, int len, int left, int right );

void print( int *a, int len );

void shift_r_n_word( int *a, int len, int n );

void reverse( int *a, int left, int right );

int binarysearch( int * a, int len, int val );

int find_shift_r_word( int *a, int len );

int main()
{
    int i;
    int r[N];
    int arr[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    node a[N];
    srand(time(NULL));
    for( i = 0; i < N; i++ )
    {
        a[i].a = rand() % N;
        a[i].b = rand() % N;
        r[i] = rand() % N;
    }
    print( r, N );
    quicksort( r, N, 0, N - 1 );
    print( r, N );
    printf("val index = %d\n", binarysearch( r, N, 10 ));

    shift_r_n_word( arr, N, 4 );
    print( arr, N );
    printf("array r shift %d word\n", find_shift_r_word( arr, N ) );

    /*
    printf("Before sort\n");
    for( i = 0; i < 20; i++ )
        printf("%d %d\n", a[i].a, a[i].b);
    printf("\n");
    qsort( a, 20, sizeof(node), compare );
    //qsort( b, 20, sizeof(int) * 2, compare );
    printf("After sort\n");
    for( i = 0; i < 20; i++ )
        printf("%d %d\n", a[i].a, a[i].b);
    */
    return 0;
}

void print( int *a, int len )
{
    int i;
    for( i = 0; i < len; i++ ) 
        printf("%d ", a[i]);
    printf("\n");
}

int compare( const void *a, const void *b )
{
    if(((node *)a)->a == ((node *)b)->a ) 
        return ((node *)a)->b - ((node *)b)->b;
    else
        return ((node *)a)->a - ((node *)b)->a; 
}

void swap( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition( int *a, int left, int right )
{
    int small = left - 1;
    int index = ( left + right ) / 2;
    swap( &a[index], &a[right] );
    index = left;
    while( index < right )
    {
        if( a[index] < a[right] )
        {
            ++small;
            if( small != index )
                swap( &a[small], &a[index] );
        }
        ++index;
    }
    ++small;
    swap( &a[small], &a[index] );
    return small;
}

void quicksort( int * a, int len, int left, int right )
{
    if( a == NULL || len == 0 )
    {
        printf("Bad input ..");
        exit(-1);
    }
    if( left < right )
    {
        int index = partition( a, left, right );
        quicksort( a, len, left, index - 1 );
        quicksort( a, len, index + 1, right );
    }
}

void reverse( int *a, int left, int right )
{
    if( a == NULL || left > right )
    {
        printf("Bad input ...\n");
        exit(-1);
    }
    while( left < right )
    {
        swap( &a[left], &a[right] );
        ++left;
        --right;
    }
}

void shift_r_n_word( int *a, int len, int n )
{
    if( a == NULL || len == 0 )
    {
        printf("Bad input ...\n");
        exit( -1 );
    }
    reverse( a, 0, len - 1 );
    reverse( a, 0, n - 1 );
    reverse( a, n, len - 1 );
}

int binarysearch( int *a, int len, int val )
{
    if( a == NULL || len == 0 )
    {
        printf("Bad input ...\n");
        exit(-1);
    }
    int index = -1;
    int left = 0;
    int right = len - 1;
    int mid = (left + right) / 2;
    while( left <= right )
    {
        if( a[mid] == val )
        {
            index = mid;
            break;
        }
        else if( a[mid] < val )
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
        else
        {
            right = mid - 1;
            mid = (left + right) / 2;
        }
    }
    return index;
}

int find_shift_r_word( int *a, int len )
{
    if( a == NULL || len == 0 )
    {
        printf("Bad input ...\n");
        exit(-1);
    }
    int left = 0;
    int right = len - 1;
    int index = left; 
    while( a[left] > a[right])
    {
        if( right - left == 1 )
        {
            index = right;
            break;
        }
        index = (left + right) / 2;
        if( a[index] >  a[left] )
            left = index;
        else if( a[index] < a[right] )
            right = index;
    }
    return index;
}
