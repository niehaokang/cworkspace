/*************************************************************************
	> File Name: isolation.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月14日 星期四 10时17分53秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#define MAX 0x7fffffff
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    map<string, int> names;
    string name1, name2;
    int k = 0;
    int **mp = new int* [m];
    for(int i = 0; i < m; i ++)
        mp[i] = new int [m];
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == j) mp[i][j] = 0;
            else mp[i][j] = MAX;
        }
    }
    for(int i = 0; i < n; i ++)
    {
        cin >> name1 >> name2;
        if(names.count(name1) == 0)
            names[name1] = k++;
        if(names.count(name2) == 0)
            names[name2] = k++;
        mp[names[name1]][names[name2]] = 1;
        mp[names[name2]][names[name1]] = 1;
    }
    for(int k = 0; k < m; k ++)
    {
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < m; j ++)
            {
               if(mp[i][j] > mp[i][k] + mp[k][j])
                    mp[i][j] = mp[i][k] + mp[k][j];
            }
        }
    }
    int res = 0;
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            if(i != j)
            {
                if(mp[i][j] == MAX)
                {
                    cout<<"DISCONNECTED"<<endl;
                    return 0;
                }
                if(mp[i][j] > res)
                    res = mp[i][j];
                }
        }
    }
   cout<<res<<endl;

   for(int i = 0; i < m; i++)
        delete [] mp[i];
   delete [] mp;
   return 0;
}

