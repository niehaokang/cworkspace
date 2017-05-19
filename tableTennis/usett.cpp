/*************************************************************************
	> File Name: usett.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Mar 2017 12:14:45 PM CST
 ************************************************************************/

#include<iostream>
#include "tabtenn.h"

int main()
{
    using namespace std;
    TableTennisPlayer tplayer("Tara", "Boomdea", false);
    RatedPlayer rplayer(1140, "Chunk", "Blizzard", true);
    rplayer.Name();
    if(rplayer.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    tplayer.Name();
    if(tplayer.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    cout << "name: ";
    rplayer.Name();
    cout << " rating: " << rplayer.Rating() << endl;
    RatedPlayer rplayer2(1212, tplayer);
    cout << "name: ";
    rplayer2.Name();
    cout << " rating: " << rplayer2.Rating() << endl;
    cout << "sizeof(TableTennisPlayer) = " << sizeof(TableTennisPlayer) << " sizeof(RatedPlayer) = " << sizeof(RatedPlayer) << endl;
    cout << "address of tplayer = " << &tplayer << " address of rplayer2" << &rplayer2 << endl;
    return 0;
}
