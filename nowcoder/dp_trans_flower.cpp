// 初始化：创建二维数组status[m][n]，初始化status[0][0]=0, status[0][1]=1, status[0][n-1]=1, ... =0
// 状态的确定：status[x][y]
// 假设小赛是第0个同学，旁边则为第1个和第n-1个，设状态为status[x][y]：x+1次传花后以第y位同学结束的序列有多少种
// 状态转移方程：
// status[x][y] = status[x-1][(y+1)%n] + status[x-1][(y+n-1)%n]
// 结果为status[m-1][0]
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	int m;
	int n;
	cin >> n >> m;
	vector<vector<int> > status(m, vector<int>(n, 0));
	status[0][1]=1;
	status[0][n-1]=1;
	for(int i = 1; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			status[i][j] = status[i-1][(j+1)%n] + status[i-1][(j+n-1)%n];
		}
	}
	cout << status[m-1][0];
	return 0;
}
