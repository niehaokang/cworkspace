/*************************************************************************
	> File Name: argc.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年03月15日 星期三 11时33分12秒
 ************************************************************************/

#include "stdio.h"
int main(int argc, char *argv[])
{
    int i;
    for(i = 0; i < argc; i++)
    {
        printf("argc[%d] = %s\n", i, argv[i]);
    }
    return 0;
}
