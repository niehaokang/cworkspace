/*************************************************************************
	> File Name: permutation.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月23日 星期日 13时57分09秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

void permutation( int n, int *index, char *c, char *array );

void Permutation( char *str );

int main()
{
    char c[4] = { 'a', 'b', 'c' };
    /*
    char c[6] = { 'a', 'b', 'c', 'd', 'e'};
    int index[5] = {0};
    char array[6];
    memset( array, 0, 6 );
    memset( index, 0, 6 * sizeof(int) );
    permutation( 0, index, c, array );
    */
    Permutation(c);
    return 0;
}

void permutation( int n, int *index, char *c, char *array  )
{
    int i;
    int len = strlen(c);
    for( i = 0; i < len; i++ )
    {
        if( index[i] != 1 )
        {
            array[n] = c[i];
            index[i] = 1;
        }
        else
            continue;
        if( array[len - 1] != '\0' )
            cout << array << endl;
        else
            permutation( n + 1, index, c, array );
        array[n] = '\0';
        index[i] = 0;
    }
}

void swap( char *p, char *q )
{
    char temp = *p;
    *p = *q;
    *q = temp;
}

void Permutation( char * str, char *begin )
{
    if( *begin == '\0' )
    {
        cout << str << endl;
    }
    else
    {
        for( char *p = begin; *p != '\0'; ++p )
        {
            swap( p, begin );
            Permutation( str, begin + 1 );
            swap( p, begin );
        }
    }
}

void Permutation( char *str )
{
    if( str == NULL )
        return;
    Permutation( str, str );
}
