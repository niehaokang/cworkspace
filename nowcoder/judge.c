/*************************************************************************
	> File Name: judge.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月04日 星期四 19时47分25秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    int arr[255];
    int a_len, b_len;
    char a[1024];
    char b[1024];
    scanf("%s", a);
    scanf("%s", b);
    memset(arr, 0, sizeof(arr));
    a_len = strlen(a);
    b_len = strlen(b);
    for( i = 0; i < a_len; i++ )
        arr[a[i]]++;
    for( i = 0; i < b_len; i++ )
    {
        if( arr[b[i]] == 0 )
        {
            printf("0\n");
            return 0;
        }
        else
            arr[b[i]]--;
    }
    printf("1\n");
    return 0;
}
