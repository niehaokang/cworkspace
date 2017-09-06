/*************************************************************************
	> File Name: number.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月06日 星期三 18时34分20秒
 ************************************************************************/

#include<iostream>  
#include<vector>  
#include<algorithm>  
using namespace std;  
  
int main()  
{  
    int nums, sum_ = 0, mul_ = 1;  
    cin >> nums;  
    vector<int> vec;      
    //从右向左找不同的元素，并放入ector中  
    while(nums >0)  
    {  
        if (find(vec.begin(), vec.end(), nums%10)== vec.end())  
            vec.push_back(nums % 10);  
        nums = nums / 10;  
    }  
    vector<int>::iterator ptr = vec.end();  
      
    //从后向前遍历vector，并求和  
    while( --ptr != vec.begin() )  
    {  
        sum_ += *ptr * mul_;  
        mul_ *= 10;  
    }  
    sum_ += *vec.begin() * mul_;  
    cout << sum_ << endl;  
    return 0;  
} 
