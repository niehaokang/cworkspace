/*************************************************************************
	> File Name: island.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月10日 星期日 19时40分54秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int main()
{
    int n, m;
    while( cin >> n >> m )
    {
        int a[n + 2][m + 2];
        memset(a, 0, (n + 2) * ( m + 2 ) * sizeof(int));
        int count = 0;
        char str[5];
        int temp1, temp2;
        queue<int> que;
        for( int i = 1; i < n + 1; i++ )
        {
            cin >> str;
            for( int j = 1; j < m + 1; j++ )
            {
                a[i][j] = str[j] - '0';
            }
        }
        for( int i = 1; i < n + 1; i++ )
        {
            for( int j = 1; j < m + 1; j++ )
            {
                if( a[i][j] == 1 )
                {
                    count++;
                    que.push(i);
                    que.push(j);
                    a[i][j] = 0;
                    while( !que.empty() )
                    {
                        temp1 = que.front();
                        que.pop();
                        temp2 = que.front();
                        que.pop();
                        if( a[temp1+1][temp2] == 1 )
                        {
                            a[temp1+1][temp2] = 0;
                            que.push(temp1+1);
                            que.push(temp2);
                        }
                        if( a[temp1][temp2+1] == 1 )
                        {
                            a[temp1][temp2+1] = 0;
                            que.push(temp1);
                            que.push(temp2+1);
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
