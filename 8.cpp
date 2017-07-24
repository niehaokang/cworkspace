/*************************************************************************
	> File Name: 8.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月23日 星期日 19时10分21秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;


void eightqueen( int n, int & count, int *queen );

bool isvalidposition( int i, int j, int *queen );

void print( int *queen );

int main()
{
    int count = 0;
    int queen[8];
    memset(queen, 0, 8 * sizeof(int));
    eightqueen( 0, count, queen);
    cout << count << endl;
    return 0;
}

void print( int *queen )
{
    int i, j, k;
    for( i = 0; i < 8; i++ )
    {
        for( j = 0; j < queen[i]; j++ )
            cout << " * ";
        cout << " # ";
        for( j = queen[i] + 1; j < 8; j++ )
            cout << " * ";
        cout << endl;
    }
    cout << endl;
}

bool isvalidposition( int a, int b, int * queen)
{
    int i;
    for( i = 0; i < a; i++)
    {
        if( b == queen[i] )
            return false;
        if( (a + queen[i]) == ( b + i ) )
            return false;
        if( (a - queen[i]) == ( i - b ) )
            return false;
    }
    return true;
}

void eightqueen( int n, int &count, int *queen )
{
    int i;
    for( i = 0; i < 8; i++ )
    {
        if( isvalidposition( n, i, queen ) )
        {
            queen[n] = i;
            if( n == 7 )
            {
                count++;
                print( queen );
                return;
            }
            eightqueen( n + 1, count, queen );
            queen[n] = 0;
        }
    }
}
