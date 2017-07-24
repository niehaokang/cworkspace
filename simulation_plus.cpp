/*************************************************************************
	> File Name: simulation_plus.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月19日 星期三 09时06分01秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#define N ( 1 << 20 )

using namespace std;

void print(char * num);

char * increase( char * num);

char * increase1( char * num);

void print_nbits( int n, char *num);

int main()
{
    int i = 0;
    int n = 4; 
    char num[n+1];
    memset(num, '0', n);
    for( i = 0; i < N; i++ )
//        increase(num);
    print_nbits( n, num);
    return 0;
}

void print(char * num)
{
    int i = 0;
    while( num[i] == '0' )
        i++;
    while( num[i] != '\0' )
        cout << num[i++];
    cout << endl;
}

void print_reverse(char *num)
{
    int len = strlen(num);
    int i = len - 1;
    while( num[i] == '0')
        i--;
    while(i >= 0 )
        cout << num[i--];
    cout << endl;
}

char * increase( char * num )
{
    int carry = 1;
    int len = strlen( num );
    int n = len;
    char cmp[len+1];
    memset(cmp, '9', len);
    while(strcmp(num, cmp))
    {
        n = len;
        carry = 1;
        while( --n >= 0 && carry == 1)
        {
            if( (int)(num[n] - '0' + carry) % 10 == 0 )
            {
                num[n] = '0';
                carry = 1;
            }
            else
            {
                num[n] += carry;
                carry = 0;
            }
        }
//        print(num);
    }
}

char * increase1( char * num )
{
    int carry = 1;
    int len = strlen( num );
    int n = len;
    int isoverflow = 0;
    while(!isoverflow)
    {
//        print(num);
        n = len;
        carry = 1;
        while( --n >= 0 && carry == 1)
        {
            if( n == 0 && num[n] == '9' && carry == 1 )
            {
                isoverflow = 1;
                break;
            }
            if( (int)(num[n] - '0' + carry) % 10 == 0 )
            {
                num[n] = '0';
                carry = 1;
            }
            else
            {
                num[n] += carry;
                carry = 0;
            }
        }
    }
}

void print_nbits( int n, char *num )
{
    int i, j;
    for( i = n - 1; i >= 0; i-- )
    {
        for( j = 0; j < 10; j++ )
        {
            num[i] = j + '0';
            if( i == 0 )
            {
                print_reverse(num);
            }
            else
                print_nbits(i, num);
        }
    }
}
