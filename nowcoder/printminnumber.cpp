/*************************************************************************
	> File Name: printminnumber.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月02日 星期三 18时51分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define max_len 10
using namespace std;

void printminnumber( int *numbers, int length );

bool compare( const char *first, const char *second );

int Compare( const void *first, const void *second );

char *strfirst = new char[ 2 * max_len + 1];
char *strsecond = new char[ 2 * max_len + 1];

int main()
{
    int nums[3] = { 32, 321, 3 };
    printminnumber( nums, 3 );
    return 0;
}

void printminnumber( int *numbers, int length )
{
    if( numbers == NULL || length == 0 )
        return;
    char ** strnums = new char*[length];
    for( int i = 0; i < length; i++ )
    {
        strnums[i] = new char[length];
        sprintf( strnums[i], "%d", numbers[i] );
    }
    for( int i = 0; i < length; i++ )
        printf( "%s", strnums[i] );
    cout << endl;
    //sort( strnums, strnums + length, compare );
    qsort( strnums, length, sizeof(char *), Compare);
    for( int i = 0; i < length; i++ )
        printf( "%s", strnums[i] );
}

bool compare( const char *first, const char *second )
{
    strcpy( strfirst, first);
    strcat( strfirst, second);

    strcpy( strsecond, second);
    strcat( strsecond, first);
    
    return ( strcmp( strfirst, strsecond) < 0 );
}

int Compare( const void *first, const void *second )
{
    strcpy( strfirst, *(char **)first );
    strcat( strfirst, *(char **)second);
    
    strcpy( strsecond, *(char **)second);
    strcat( strsecond, *(char **)first);
    cout << strfirst << " " << strsecond << endl;
    cout << strcmp( strfirst, strsecond ) << endl;;
    return ( strcmp( strfirst, strsecond ) );
}
