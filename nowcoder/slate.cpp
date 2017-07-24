/*************************************************************************
	> File Name: slate.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月21日 星期五 20时50分03秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int m, n;
    int i, j;
    cin >> m >> n;
    unsigned steps[n + 1];
    memset( steps, 0xff, (n + 1) * 4 );
    steps[m] = 0;
    for( i = m + 1; i <= n; i++ )
    {
        int temp = i * 2 / 3;
        for( j = temp>m?temp:m; j < i - 1; j++ )
        {
            if( j % (i - j) == 0 && steps[i] - 1 > steps[j])
                steps[i] = steps[j] + 1;
        }
    }
    cout << steps[n] << endl;
    return 0;
}
