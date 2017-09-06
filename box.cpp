/*************************************************************************
	> File Name: box.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月28日 星期一 19时59分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &s){
	for(int i=0;i<6;i++){
		if(s[i]!=0){
			return true;
		}
	}
	return false;
}

int minBox(vector<int> &s){
	vector<int> r(6);
	vector<int> e(6,0);
	r[5]=s[5];
	e[5]=0;
	r[4]=r[5]+s[4];
	e[4]=11*s[4];
	r[3]=r[4]+s[3];
	e[3]=s[3]*20;
	r[2]=r[3]+(s[2]%4==0?s[2]/4:s[2]/4+1);
	if(s[2]%4!=0){
		e[2]=(4-s[2]%4)*9;
	}else{
		e[2]=0;
	}
	e[1]=s[1];
	if(e[1]>=e[3]/4){
		e[1]-=e[3]/4;
		e[3]=0;
	}else{
		e[3]-=4*e[1];
		e[1]=0;
	}
	if(e[1]>=e[2]/4){
		e[1]-=e[2]/4;
		e[2]=0;
	}else{
		e[2]-=4*e[1];
		e[1]=0;
	}
	e[1]=e[1]<0?0:e[1];

	r[1]=r[2]+(e[1]%9==0?e[1]/9:e[1]/9+1);
	e[0]=s[0];
	for(int i=5;i>=0;i--){
		e[0]-=e[i];
	}
	e[0]=e[0]<0?0:e[0];
	r[0]=r[1]+(e[0]%36==0?e[0]/36:e[0]/36+1);
	
	return r[0];
}

int main(int argc, char *argv[])
{
	vector<int> s;
	bool state=false;

	int t;
	while(cin>>t){
		s.clear();
		s.push_back(t);
		for(int i=0;i<5;i++){
			cin>>t;
			s.push_back(t);
		}
		if(!check(s)){
			break;
		}else{
			cout<<minBox(s)<<endl;
		}
	}

	return 0;
}
