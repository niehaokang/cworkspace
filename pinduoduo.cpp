/*************************************************************************
	> File Name: pinduoduo.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月 2日 18:19:03
 ************************************************************************/

#include<iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct TreeNode{
public:
	TreeNode(int a,string b){
		id=a;
		name=b;
	}
	int id;
	string name;
	vector<TreeNode*> nodes;
};

map<int,TreeNode*> mmap;

void process(TreeNode *top,int d){
	int n=top->nodes.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(top->nodes[j+1]->name<top->nodes[j]->name){
				TreeNode *t=top->nodes[j+1];
				top->nodes[j+1]=top->nodes[j];
				top->nodes[j]=t;
			}
		}
	}
	for(int i=0;i<top->nodes.size();i++){
		if(d!=0){
			for(int j=0;j<d-1;j++){
				cout<<"    ";
			}
			if(i!=top->nodes.size()-1){
				cout<<"|-- ";
			}else{
				cout<<"'-- ";
			}
		}
		cout<<top->nodes[i]->name<<endl;
		if(top->nodes.size()==0){
			cout<<endl;
		}else{
			process(top->nodes[i],d+1);
		}
	}
}

int main(int argc, char *argv[])
{
	vector<pair<string,int> > s;
	int n;
	cin>>n;
	mmap[-1]=new TreeNode(-1,"");
	for(int i=0;i<n;i++){
		string a;
		int b;
		cin>>a>>b;
		mmap[i]=new TreeNode(i,a);
		mmap[b]->nodes.push_back(mmap[i]);
	}
	process(mmap[-1],0);
	
	return 0;
}


