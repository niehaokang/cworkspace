/*************************************************************************
	> File Name: malloc.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月29日 星期二 21时47分15秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int **p;
    p = ( int **)malloc( 3 * sizeof( int * ) );
    for( int i = 0; i < 3; i++ )
        p[i] = ( int * ) malloc( 5 * sizeof( int ) );
    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 5; ++j)
            p[i][j] = i * 10 + j;
    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 5; ++j)
            cout << p[i][j] << endl;
    int (*a)[2] = ( int(*)[2] )malloc( 5 * 2 * sizeof(int));
    for( int i = 0; i < 5; ++i )
        for( int j = 0; j < 2; ++j)
            a[i][j] = i * 10 + j;
    for( int i = 0; i < 5; ++i )
        for( int j = 0; j < 2; ++j)
            cout << a[i][j] << endl;
    return 0;
}
