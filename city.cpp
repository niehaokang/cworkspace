/*************************************************************************
	> File Name: city.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月09日 星期六 16时49分18秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int,vector<int> > mmap;

int maxCity(vector<bool> &vec,int m,int c,int count){
    int result=0;
    if(count==m){
        return 0;
    }
    for(int i=0;i<mmap[c].size();i++){
        if(!vec[mmap[c][i]]){
            vec[mmap[c][i]]=true;
            int tmp=1+maxCity(vec,m,mmap[c][i],count+1);
            result=result>tmp?result:tmp;
            vec[mmap[c][i]]=false;
        }else{
            int tmp=maxCity(vec,m,mmap[c][i],count+1);
            result=result>tmp?result:tmp;
        }
    }
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> visited(n,false);
    visited[0]=true;
    for(int i=0;i<n-1;i++){
        int t;
        cin>>t;
        if(t>=0&&t<n){
            mmap[t].push_back(i+1);
        	mmap[i+1].push_back(t);
        }
    }
    cout<<1+maxCity(visited,m,0,0)<<endl;
    return 0;
}
