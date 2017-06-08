#include<stdio.h>
int main()
{
	int m,n,i,x,y,s,key;
	while(~scanf("%d%d",&m,&n)){
		y=m,s=0,key=0;
		for(i=0;i<=n;i++){
			scanf("%d",&x);
			if(key)
			    continue;
			if(y>=x){
				y-=x;
			}
			else{
				y=m-x;
				if(y<0){
					key=1,s=0;
					continue;
				}
				    
				s++;
			}  
		}
		printf("%d\n",s);
	}
} 
