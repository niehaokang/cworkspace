#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  int n,m;
  float a[600];
  cin >> n;
  double s = 0,k = 0;
  for(int i = 0;i < n;i++)
  	  cin >> a[i];
  	sort(a,a + n);
  for(int j = n - 1;j >= 0;j--){
	  s += (sqrt(a[j] * a[j] - 1)) * 2;
	  k++;
	  if(s > 20){
	    cout << k << endl;
	    break;
	  }
   }
}
