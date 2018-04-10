/*************************************************************************
	> File Name: QuickSort.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月22日 星期五 18时17分32秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &s,int l,int h){
    if(l>=h){
        return;
    }
    int a=l,b=h;
    while(a<b){
        while(a<b&&s[b]>=s[a]){
            b--;
        }
        s[a]=s[b];
        while(a<b&&s[a]<=s[b]){
            a++;
        }
        s[b]=s[a];
    }
    quickSort(s,l,a-1);
    quickSort(s,a+1,h);
}

void swap( int &a, int &b )
{
    int temp = a;
    a = b;
    b = temp;
}

int partiotion( int *a, int left, int right )
{
    int small = left - 1;
    swap( a[left], a[right] );
    int index;
    for( index = left; index < right; index++ )
    {
        if( a[index] < a[right] )
        {
            ++small;
            if( small != index )
                swap( a[small], a[index] );
        }
    }
    ++small;
    swap(a[small], a[right]);
    return small;
}

void quick( int *a, int left, int right)
{
    if( a == NULL || left >= right )
        return;
    int index;
    index = partiotion( a, left, right);
    quick(a, left, index - 1);
    quick(a, index + 1, right);
}

int main(){
    int a[]={4,2,5,6,7,13,87,45,3};
    quick( a, 0, 8 );
    for( int i = 0; i < sizeof(a) / sizeof( int ); i++ )
        cout << a[i] << " ";
    cout << endl;
    /*
    vector<int> s;
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        s.push_back(a[i]);
    }
    quickSort(s,0,s.size()-1);
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    */
    return 0;
}
