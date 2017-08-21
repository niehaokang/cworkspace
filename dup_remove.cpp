/*************************************************************************
	> File Name: dup_remove.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月19日 星期六 19时57分02秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<set>
using namespace std;
int main()
{
    set<int> int_set;
    ifstream f_in("random.in");
    ofstream f_out("random.out");
    int temp;
    int count = 0;
    f_in >> temp;
    while( f_in >> temp )
        int_set.insert( temp );
    set<int> ::iterator it;
    for( it = int_set.begin(); it != int_set.end(); it++ )
        count++;
    f_out << count << endl;
    int i = 0;
    for( it = int_set.begin(); i < count - 1; i++, it++ )
        f_out << *it << " ";
    f_out << *it;
    return 0;
}
