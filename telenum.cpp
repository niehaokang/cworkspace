/*************************************************************************
	> File Name: telenum.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月06日 星期三 18时48分58秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string num[10];
    vector<string> ans;
    int digit[10];
    char tmp[10];
    int n;

    void dfs(int depth)
    {
        if(depth == n)
        {
            string s(tmp);
            ans.push_back(s);
        }

        for(int i=0; i<num[digit[depth]].size(); i++)
        {
            tmp[depth] = num[digit[depth]][i];
            dfs(depth+1);
        }
    }
    vector<string> & letterCombinations(string &digits) 
    {
        num[0] = "";
        num[1] = "";
        num[2] = "abc";
        num[3] = "def";
        num[4] = "ghi";
        num[5] = "jkl";
        num[6] = "mno";
        num[7] = "pqrs";
        num[8] = "tuv";
        num[9] = "wxyz";
        n = digits.length();
        if(n == 0)
            return ans;
        for(int i=0; i<n; i++)
            digit[i] = digits[i] - '0';
        dfs(0);
        return ans;
    }
};

int main()
{
    string digit = "234";
    Solution *s = new Solution();
    vector<string> vs = s->letterCombinations(digit); 
    vector<string>::iterator it;
    for( it = vs.begin(); it != vs.end(); it++ )
        cout << *it << endl;
    return 0;
}
