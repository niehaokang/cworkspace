#include <iostream>

using namespace std;

long GCD(long a,long b);

int main(int argc,char* argv[]){
	long n,c;
	while(cin>>n>>c){ 
		int *b=new int[n];
		for(int i=0;i<n;i++)
			cin>>b[i];
		for(int i=0;i<n;i++){
			if(c>=b[i])
				c+=b[i];
			else
				c+=GCD(c,b[i]);
		}
		cout<<c<<endl;
	}
	return 0;
}

long GCD(long a,long b){
	if(a<b)
		swap(a,b);
	while(b!=0){
		int c= a %b;
		a=b;
		b=c;
	}
	return a;
}
