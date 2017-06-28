/*************************************************************************
	> File Name: sort_array.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月13日 星期二 21时12分09秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    int a;
    int b;
};

bool compare(const node &a, const node &b)
{
    if( a.a > b.a )
        return true;
    else if( a.a == b.a && a.b > b.b )
        return true;
    else
        return false;
}

int main()
{
    int i;
    node array[10];
    for( i = 0; i < 10; i++ )
    {
        array[i].a = rand() % 10;
        array[i].b = rand() % 10;
    }
    for( i = 0; i < 10; i++ )
        cout << array[i].a << " " << array[i].b << endl;
    sort( array, array + 10, compare );
    cout << endl;
    for( i = 0; i < 10; i++ )
        cout << array[i].a << " " << array[i].b <<endl;
    return 0;
}
