/*************************************************************************
	> File Name: sort.c
	> Author: Datou_Nie 
	> Mail: niehaokang@gmail.com 
	> Created Time: Mon 27 Mar 2017 11:28:53 AM CST
 ************************************************************************/

#include<stdio.h>

void printf_line(int *a, int size);
void swap(int *p, int *q);
int insert_sort(int * a, int size);
int bubble_sort(int * a, int size);
int select_sort(int * a, int size);
int count_sort(int * a, int size);
int fast_sort(int * a, int size);
int heap_sort(int * a, int size);

int main()
{
    int i;
    int a[10] = {9, 6, 0, 1, 2, 5, 3, 4, 7, 8};
    int a1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[10] = {9, 6, 6, 6, 8, 5, 3, 4, 7, 8};
    printf("before sort\n");
    printf_line( a, 10 );
//    insert_sort(a, 10);
//    bubble_sort(a, 10);
//    select_sort(a, 10);
//    count_sort(a, 10);
//    fast_sort(a, 10);
    heap_sort(a, 10);
    printf("after sort\n");
    printf_line( a, 10 );
    return 0;
}

void printf_line(int *a, int size)
{
    int i;
    for( i = 0; i < size; i++ )
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int insert_sort(int * a, int size)
{
    int i, j;
    int temp;
    for( i = 1; i < size; i++ )
    {
        temp = a[i];
        j = i - 1;
        while( a[j] > temp && j >= 0 )
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    return 0;
}

int bubble_sort(int * a, int size)
{
    int i, j;
    int count;
    int temp;
    for( i = 0; i < size - 1; i++ )
    {
        count = 0;
        for( j = 0; j < size - i - 1; j++ )
        {
            if( a[j] > a[j + 1] )
            {
                count ++;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if( count == 0 )
            break;
    }
    return 0;
}

int select_sort(int * a, int size)
{
    int i, j;
    int min;
    int temp;
    for( i = 0; i < size; i++ )
    {
        min = i;
        for( j = i + 1; j < size; j++ )
            if(a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    return 0;
}

int count_sort(int *a, int size)
{
    int i, j;
    int b[size];
    int c[size];
    for( i = 0; i < size; i++ )
        c[i] = 0;
    for( i = 0; i < size; i++ )
        c[a[i]]++;
    for( i = 1; i < size; i++ )
        c[i] += c[i - 1];
    for( i = size - 1; i >=0; i-- )
    {
        b[c[a[i]]-1] = a[i];
        --c[a[i]];
    }
    printf_line(b, size);
    return 0;
}

void inner_fast_sort(int *a, int left, int right)
{
    if( left >= right )
        return;
    int i = left, j = right;
    int temp = a[left];

    while( i < j )
    {
        for( ; i < j && a[j] > temp; j-- );
        a[i] = a[j];

        for( ; i < j && a[i] < temp; i++ );
        a[j] = a[i];
    }
    a[i] = temp;
    inner_fast_sort(a, left, i - 1);
    inner_fast_sort(a, i + 1, right);
}

int fast_sort(int * a, int size)
{
    inner_fast_sort(a, 0, size - 1);
    return 0;
}

void inner_adjust_two_child(int *p, int *q, int *r)
{
    if( *p > *q && *p > *r)
        swap( p, r );
    else if( *q > *p && *q > *r )
        swap( q, r );
}

void inner_adjust_one_child(int *p, int *r)
{
    if( *p > *r)
        swap( p, r );
}
int heap_sort(int *a, int size)
{
    int i, j;
    int right_child;
    int d;
    for( i = size - 1; i > 0; i-- )
   {
        d = ((i + 1) >> 1) - 1;
        j = d;
        for( j = d; j >= 0; j-- )
        {
            right_child = (j << 1) + 2;
            if( right_child <=  i )
                inner_adjust_two_child(&a[right_child - 1], &a[right_child], &a[j]);
            else
                inner_adjust_one_child(&a[right_child - 1], &a[j]);
        }
        swap( &a[0], &a[i] );
    }
    return 0;
}
