/*************************************************************************
	> File Name: youya.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月25日 星期六 11时23分30秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
    int s;
    scanf("%d", &s);
    int i, j, k;
    int count = 0;
    for(i=0; i * i < s; i++);
    if(i * i == s)
        count ++;
    for(j=1; j < i; j++)
    {
        for(k=1; k < i; k++)
        {
            if(j * j + k * k < s){
                continue;
            }
            else if(j * j + k * k == s){
                count ++;
                break;
            } else {
                break;
            }
        }
    }
    printf("%d\n",4 * count);
    return 0;
}
