#include <iostream>
#include <vector>
using namespace std;

int check(vector<int> &s,int k){
	int n=s.size();
	int result=0;
	vector<int> sum(n,0);
	sum[0]=s[0]%k;
	vector<pair<int,int> > p(k);
	for(int i =0;i<k;i++){
		p[i]=make_pair(-1,-1);
	}
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+s[i];
		sum[i]%=k;
	}

	for(int i=n-1;i>=0;i--){
		if(sum[i]==0){
			result=i+1;
			break;
		}
	}

	for(int i=0;i<n;i++){
		if(p[sum[i]].first==-1){
			p[sum[i]].first=p[sum[i]].second=i;
		}else{
			p[sum[i]].first=p[sum[i]].first<i?p[sum[i]].first:i;
			p[sum[i]].second=p[sum[i]].second>i?p[sum[i]].second:i;
		}

	}

	for(int i=0;i<k;i++){
		if(p[i].first==-1){
			continue;
		}
		int t=p[i].second-p[i].first;
		result=result<t?t:result;
	}
	return result;
}

int main(int argc, char *argv[])
{
	int n,k;
	vector<int> s;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.push_back(t);
	}
	cin>>k;
	cout<<check(s,k)<<endl;
	
	return 0;
}
