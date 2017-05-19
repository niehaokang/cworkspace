#include<iostream>
using namespace std;

int main(){
int l,r,m,count,out=0;
cin >> l>>r>>m;
for(int i=l;i<=r;i++){
	count=0;
	int n=i;
	while(n!=0){
	n=n&(n-1);
	count++;
	}
	if(count==m){
	out++;
	}
}
if(out==0)
out=-1;
cout << out;

}
