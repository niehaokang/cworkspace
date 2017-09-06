/*************************************************************************
	> File Name: kola.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月28日 星期一 20时04分16秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>
vector<int> kola(vector<int> des, vector<int> src) {
	vector<int> v;
	for (int i=0,p=0;i<des.size();i++,p++)
	{
		p = p%src.size();
		for (int j=0;j<des[i];j++)
		{
			v.push_back(src[p]);
		}
	}
	return v;
 }


int main() {
	int m, n;
	cin >> m >> n;
	int tmp = n;
	vector<int> vec;
	while (n--)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}
	vector<int> res;
	res = kola(vec, vec);
	while (res.size()<=m)
	{
		res = kola(res, vec);
	}
	for (int i=0;i<m;i++)
	{
		cout << res[i] << endl;
	}
    return 0;
 }
