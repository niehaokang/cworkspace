/*************************************************************************
	> File Name: char_judge.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月04日 星期四 16时55分20秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int is_include(int *a, int *b);
int calculate( int *a, int temp[][3] );

int main()
{
    int i;
    int a[1024];
    int b[1024];
    for( i = 0; i < 5; i++ )
        scanf("%d", &a[i]);
    a[5] = -1;
    for( i = 0; i < 5; i++ )
        scanf("%d", &b[i]);
    b[5] = -1;
    is_include(a, b);
    return 0;
}

int is_include(int *a, int *b)
{
    int i, j;
    int flag;
    int a_temp[10][3];
    int b_temp[10][3];
    int a_index = 0;
    int b_index = 0;
    memset(a_temp, 0, sizeof(a_temp));
    memset(b_temp, 0, sizeof(b_temp));
    a_index = calculate(a, a_temp);
    b_index = calculate(b, b_temp);
    for(i = 0; i < a_index; i++)
    {
        if(a_temp[i][0] >= 0x80)
        {
            printf("%d %d %d\n", a_temp[i][0], a_temp[i][1], a_temp[i][2]);
        }
        else
            printf("%d\n", a_temp[i][0]);
    }
    for(i = 0; i < b_index; i++)
    {
        if(b_temp[i][0] >= 0x80)
        {
            printf("%d %d %d\n", b_temp[i][0], b_temp[i][1], b_temp[i][2]);
        }
        else
            printf("%d\n", b_temp[i][0]);
    }
    if( a_index < b_index )
    {
        printf("false\n");
        return 0;
    }
    else
    {
        for( i = 0; i < b_index; i++ )
        {
            flag = 0;
            for( j = 0; j < a_index; j++ )
            {
                if(b_temp[i][0] == a_temp[j][0] && b_temp[i][1] == a_temp[j][1] && b_temp[i][2] <= a_temp[i][2])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("false\n");
                return 0;
            }
        }
    }
    printf("true\n");
}

int calculate( int *a, int temp[][3] )
{
    int i, j;
    int flag;
    int index = 0;
    while(*a > 0 )
    {
        flag = 1;
        for( i = 0; i < index; i++ )
        {
            if( *a >= 0x80 )
            {
                if( *a == temp[i][0] && *(a + 1) == temp[i][1] )
                {
                    temp[i][2]++;
                    a += 2;
                    flag = 0;
                    break;
                }
            }
            else
            {
                if( *a == temp[i][0] )
                {
                    a++;
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)
        {
            if( *a >= 0x80 )
            {
                temp[index][0] = *a;
                temp[index][1] = *(a + 1);
                temp[index][2] = 1;
                a += 2;
            }
            else
            {
                temp[index][0] = *a;
                a++;
            }
            index++;
        }
    }
    return index;
}
