/*************************************************************************
	> File Name: coupleprime.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月25日 星期二 21时15分08秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 500 
bool isprime( int n );
int main()
{
    int i, j;
    int count = 0;
    int prime[N];
    int primeindex = 0;
    int n;
    cin >> n;
    for( i = 2; i < n; i++ )
        if( isprime( i ))
            prime[primeindex++] = i;
    //for( i = 0; i < primeindex; i++ )
    //    cout << prime[i] << " ";
    for( i = 0, j = primeindex - 1; i != j; )
    {
        if( prime[i] + prime[j] == n )
        {
    //        cout << prime[i] << " " << prime[j] << endl;
            ++count;
            ++i;
            --j;

        }
        else if( prime[i] + prime[j] > n )
            --j;
        else
            ++i;
    }
    if( n / 2 == prime[i] )
        count++;
    cout << count << endl;
    return 0;
}


bool isprime( int n)
{
    for( int i = 2; i * i <= n; i++ )
        if( n % i == 0 )
            return false;
    return true;
}
