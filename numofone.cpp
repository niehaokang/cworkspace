/*************************************************************************
	> File Name: numofone.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月18日 星期二 21时19分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N ( 1 << 25 )

int number_of_set_bits(int i);

int BitCount(unsigned int n);

int bitcount( int n );

int normal( unsigned int n );

int main()
{
    int i;
    int n = 0xffffffff;
    for( i = 0; i < N; i++ )
        number_of_set_bits(n);
    cout << normal(n) << endl;
    return 0;
}

int number_of_set_bits(int i)
{ 
    i = i - ((i >> 1) & 0x55555555); 
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333); 
    return (((i + (i >> 4)) & 0x0f0f0f0f) * 0x01010101) >> 24;
}

int BitCount(unsigned int n) 
{ 
    n = (n &0x55555555) + ((n >>1) &0x55555555) ; 
    n = (n &0x33333333) + ((n >>2) &0x33333333) ; 
    n = (n &0x0f0f0f0f) + ((n >>4) &0x0f0f0f0f) ; 
    n = (n &0x00ff00ff) + ((n >>8) &0x00ff00ff) ; 
    n = (n &0x0000ffff) + ((n >>16) &0x0000ffff) ; 

    return n ; 
}

int bitcount( int n )
{
    int count = 0;
    while( n )
    {
        n &= n -1;
        count++;
    }
    return count;
}

int normal( unsigned int n )
{
    int count = 0;
    while( n )
    {
        if( n & 1 )
            count++;
        n >>= 1;
    }
    return count;
}
