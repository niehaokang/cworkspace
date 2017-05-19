/*************************************************************************
	> File Name: atoi.c
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Mar 2017 09:26:17 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define INT_MAX  2147483647
#define INT_MIN -2147483648
int myAtoi(char *str);

int main()
{
    char str1[100] = "         +1031093871";
    char str2[100] = "        c +1031093871";
    char str3[100] = "        c +1031093871";
    char str4[100] = "        jfdla +1031093871";
    int num = myAtoi(str1);
    printf("%d", num);
    return 0;
}

int myAtoi(char *str)
{
    int sign = 1;
    int total = 0;
    int temp;
    int q = INT_MAX/10;
    int r = INT_MAX%10;
    int r_= r + 1;

    printf("run to here\n");
    while(*str == ' ')
        str++;

    if(*str == '+')
        sign = 1;
    else if(*str == '-')
        sign = -1;

    str++;
    while(*str != '\0')
    {
        if(*str >= '0' && *str <= '9')
        {
            temp = (int)(*str - '0');
            if(sign = 1)
            {
                if(total > q || (total == q && temp > r))
                    return INT_MAX;
            }else
            {
                if(total > q || (total == q && temp > r_))
                    return INT_MIN;
            }
            total = total * 10 + temp;
        }
        else
            return -1;
        str++;
    }
    return total * sign;
}
