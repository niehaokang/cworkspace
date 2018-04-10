/*************************************************************************
	> File Name: magic.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月08日 星期五 20时02分37秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPartition(vector<int>& nums);

int main()
{
    int num = 242;
    int l, r;
    int count = 0;
    int temp;
    cin >> l >> r;
    for( int i = l; i < r; i++ )
    {
        vector<int> magicvec;
        temp = i;
        while( temp != 0 )
        {
            magicvec.push_back(temp % 10);
            temp = temp / 10;
        }
        if( canPartition(magicvec) )
            ++count;
    }
    cout << count << endl;
    return 0;
}

bool canPartition(vector<int>& nums)
{  
    int sum = accumulate(nums.begin(), nums.end(), 0);  
    if(sum&1) return false;  
    vector<int> dp(sum/2+1, 0);  
    dp[0] = 1;
    for(int i = 0 ; i < nums.size(); i++)  
    {  
        for(int j = sum/2; j >= nums[i]; j--)  
        dp[j] = dp[j] || dp[j-nums[i]];  
    }  
    return dp[sum/2];
}
