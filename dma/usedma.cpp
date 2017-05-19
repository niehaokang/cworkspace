/*************************************************************************
	> File Name: usedma.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月10日 星期一 15时50分45秒
 ************************************************************************/

#include<iostream>
#include "dma.h"
using namespace std;

int main()
{
    baseDMA shirt ("Portabelly", 8);
    lacksDMA balloon ("Red", "Blimpo", 4);
    hasDMA map ("Mercator", "Buffalo Keys", 5);
    cout << shirt << endl;
    cout << balloon << endl;
    cout << map << endl;
    lacksDMA balloon2( balloon );
    hasDMA map2;
    map2 = map;
    cout << balloon2 << endl;
    cout << map2 << endl;
    return 0;
}
