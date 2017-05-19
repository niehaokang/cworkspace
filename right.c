#include <stdio.h>
#include <stdlib.h>
#define INT_MIN 0x80000000
int comp(const void * p1,const void * p2) {
  return *(int*)p1 > *(int*)p2 ? 1:-1;
}
int main ( ) {
  int n,m;
  int i;
  int j;
  scanf("%d",&n);
  int ta[n+1];
  for(i = 0;i < n; ++i) {
	scanf("%d",ta+i);
  }
  ta[n] = ta[n-1]+1;
  scanf("%d",&m);
  int tb[m+1];
  for(i = 0;i < m; ++i) {
  	scanf("%d",tb+i);
  }
  ta[n] = tb[m] = (ta[n-1]>tb[m-1]?ta[n-1]:tb[m-1]) +1; //border
  qsort(ta,n,sizeof(int),comp);
  qsort(tb,m,sizeof(int),comp);
  int max_diff = INT_MIN;
  int diff;
  j = 0;
  for (i=0; i<=n; i++) {
	for(; j<=m; j++)
	  if(tb[j]>=ta[i])
		break;
	diff = 2*i+(n-i)*3 - (2*j+(m-j)*3);
	if (diff > max_diff) {
	  max_diff = diff;
	}
  }
  printf("%d",max_diff);
}
