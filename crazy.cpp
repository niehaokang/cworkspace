//
// Created by yudw on 2017/8/12.
//

#include <iostream>
#include <algorithm>
#include<vector>
#include <deque>
using namespace std;

/*
3.疯狂队列，贪心方法，每一次将最大的疯狂值的序列加入
*/



int main()
{
    int n;
    while (cin>>n)
    {
        vector<int> vec_h(n);
        for (size_t i=0; i<n; ++i)
        {
            cin>>vec_h[i];
        }
        sort(vec_h.begin(), vec_h.end());
        deque<int> deque_crazy;
        deque_crazy.push_back(vec_h[0]);
        for (int i = 1, j = n-1; deque_crazy.size() != n; )
        {
            int head = deque_crazy.front();
            int tail = deque_crazy.back();
            int crazy1 = abs(head - vec_h[i]);
            int crazy2 = abs(head - vec_h[j]);
            int crazy3 = abs(tail -vec_h[i]);
            int crazy4 = abs(tail - vec_h[j]);
            if(max(crazy1, max(crazy2, max(crazy3, crazy4))) == crazy1)
            {
                deque_crazy.push_front(vec_h[i]);
                ++i;
            } else if(max(crazy1, max(crazy2, max(crazy3, crazy4))) == crazy2)
            {
                deque_crazy.push_front(vec_h[j]);
                --j;
            }else if(max(crazy1, max(crazy2, max(crazy3, crazy4))) == crazy3)
            {
                deque_crazy.push_back(vec_h[i]);
                ++i;
            } else
            {
                deque_crazy.push_back(vec_h[j]);
                --j;
            }
        }
        int ans =0;
        for(size_t i=1; i<n; ++i)
        {
            ans += abs(deque_crazy[i] - deque_crazy[i-1]);
        }
        cout<<ans<<endl;

    }
    return 0;
}
