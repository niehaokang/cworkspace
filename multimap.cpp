/*************************************************************************
	> File Name: multimap.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月16日 星期五 08时59分44秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef int KeyType;
typedef pair< const KeyType, string > Pair;
typedef multimap< KeyType, string > MapCode;

int main()
{
    MapCode codes;
    codes.insert( Pair(415, "San Francisco") );
    codes.insert( Pair(510, "Oakland") );
    codes.insert( Pair(718, "Brooklyn") );
    codes.insert( Pair(718, "Staten Island") );
    codes.insert( Pair(415, "San Rafael") );
    codes.insert( Pair(510, "Berkeley") );

    cout << " Number of cities with area code 415: " << codes.count(415) << endl;
    cout << " Number of cities with area code 718: " << codes.count(510) << endl;
    cout << " Number of cities with area code 718: " << codes.count(718) << endl;
    cout << "Area Code City\n";
    MapCode::iterator it;
    for( it = codes.begin(); it != codes.end(); ++it )
        cout << " " << (*it).first << " " << (*it).second << endl;

    pair< MapCode::iterator, MapCode::iterator > range = codes.equal_range(718);
    cout << "Cities with area code 718: \n";
    for( it = range.first; it != range.second; ++it )
        cout << (*it).second << endl;
    return 0;
}

