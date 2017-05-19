//
// Created by Xue Li on 2017/4/11.
//


#include <iostream>
#include <vector>
#include<memory.h>

using namespace std;

/*动态规划解0-1背包问题：
 * 从所有target中移除某些节点，保证剩余ip之和不小于superior的in，从而减小总cost，
 * 也就相当于选择一些节点，保证ip之和小于in的余量（所有target的ip之和减去superior的in），最大化cost之和。
 *
 * information的余量作为包重量的限制;
 * 每个target的ip作为物品重量;
 * 每个target的cost作为物品价值;
 */
int zero_one(int n, vector<int> cost, vector<int> inf){
    int max_cost = 0;
    int max_inf = 0;
    int len = inf.size()-1;
    for (int i = 1; i <= len; i++)
        max_inf += inf[i];
    for (int i = 1; i <= len; i++)
        max_cost += cost[i];
    if (max_inf < n)
        return -1;
    if (max_inf == n)
        return max_cost;

    int inf_lmt = max_inf - n;
    vector<vector<int> > dp(len + 1, vector<int>(inf_lmt+1));
    for (int j = 0; j < inf_lmt+1; j++)
        dp[0][j] = 0;
    for(int i = 0; i < len+1; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= len; i++){
        for (int j = 1; j <= inf_lmt; j++){
            dp[i][j] = dp[i-1][j];
            if ((j >= inf[i]) && ((dp[i-1][j-inf[i]] + cost[i]) > dp[i][j]))
                dp[i][j] = dp[i-1][j-inf[i]] + cost[i];
        }
    }
    return max_cost - dp[len][inf_lmt];
}

//相当于一个自底向上的过程，先处理完某node的所有下属node，然后处理这个node
int oneNode(int num, int in, vector<vector<int> >& child, vector<int>& p_cost, vector<vector<int> >& targets){
    //这里主要是想希望下标从1开始，所以前面加了一个填充数
    //vector<int> inf = {0};
    vector<int> inf;
    //vector<int> cost = {0};
    vector<int> cost;
    for (int i = 0; i < child[num].size(); i++){
        int c = child[num][i];
        if (p_cost[c] < 0){
            oneNode(c, targets[c][1], child, p_cost, targets);
        }
        if (p_cost[c] >= 0) {
            cost.push_back(p_cost[c]);
            inf.push_back(targets[c][2]);
        }
    }
    int branch = zero_one(in, cost, inf);
    p_cost[num] = branch;
    if (branch < 0)
        return branch;
    p_cost[num] += targets[num][3];
    return p_cost[num];
}

int main(){
    int n;
    cin >> n;
    int root = 0;
    vector<vector<int> > targets(n+1, vector<int>(4));
    vector<vector<int> > child(n+1);
    vector<int> cost(n+1, -1);
    for (int i = 1; i <= n; i++){
        memset(child[i].data(), 0 ,child[i].size()*sizeof(vector<int>));
//        child[i] = {};
    }
    for (int i = 1; i <= n; i++){
        int f, in, ip, c;
        cin >> f >> in >> ip >> c;
        targets[i][0] = f;
        targets[i][1] = in;
        targets[i][2] = ip;
        targets[i][3] = c;

        if (in == 0) {
            cost[i] = c;
        }
        child[f].push_back(i);
        if (f == 0)
            root = i;
    }

    int rst = oneNode(root, targets[root][1], child, cost, targets);

    cout << rst;
    return 0;
}
