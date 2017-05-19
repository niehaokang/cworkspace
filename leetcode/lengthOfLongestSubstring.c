/*************************************************************************
	> File Name: lengthOfLongestSubstring.c
	> Author:
	> Mail:
	> Created Time: Mon 27 Mar 2017 10:01:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int lengthOfLongestSubstring(char *s);
int lengthOfLongestSubstring_right(char *s);
int lengthOfLongestSubstring_best(char *s);

int main()
{
    int max_len;
    char str1[10] = "Datou_nie";
    char str2[10] = "abcedefa";
    char str3[10] = "naielhao";
    char str4[4] = "aab";
    char str5[5] = "dvdf";
    char str6[10] =  "asjrgapa";
    char str7[10] = "jbpnbwwd";
    char str8[5] = "abc";
    int i;
    for( i = 0; i < 1024 * 1024; i++ )
        max_len = lengthOfLongestSubstring_best(str4);
    printf("maxlength = %d\n", max_len);
    for( i = 0; i < 1024 * 1024; i++ )
        max_len = lengthOfLongestSubstring(str4);
    printf("maxlength = %d\n", max_len);
    return 0;
}

int lengthOfLongestSubstring_right(char *s)
{
    int a[128] = {0};
    char *p;
    int i, j, k;

    int count = 0;
    int max = 0;

    p = s;
    i = 0;

    while( *p != '\0' )
    {
        while( *p != '\0')
        {
            a[*p] += 1;
            for( j = 0; j < 128; j++ )
            {
                if(a[j] > 1)
                {
                    for( k = 0; k < 128; k++ )
                        a[k] = 0;
                    count = 0;
                    goto here;
                }
            }
            count ++;
            if( count > max )
                max = count;
            p++;
        }
here:
        i++;
        p = s + i;
    }
    return max;
}
#if 0
int lengthOfLongestSubstring(char *s)
{
    int a[128] = {0};
    char *p;
    int i, j, k;

    int count = 0;
    int max = 0;

    p = s;

    while( *p != '\0')
    {
        a[*p] += 1;
        for( j = 0; j < 128; j++ )
        {
            if(a[j] > 1)
            {
                p --;
                while( *p != j )
                    p--;
                for( k = 0; k < 128; k++ )
                    a[k] = 0;
                count = 0;
                goto here;
            }
        }
        count ++;
        if( count > max )
            max = count;
here:
        p++;
    }
    return max;
}

int lengthOfLongestSubstring(char *s)
{
    int a[128] = {0};
    char *p;
    int i, j, k;

    int count = 0;
    int max = 0;

    p = s;

    while( *p != '\0')
    {
        a[*p] += 1;
        for( j = 0; j < 128; j++ )
        {
            if(a[j] > 1)
            {
                p --;
                while( *p != j )
                    p--;
                for( k = 0; k < 128; k++ )
                    a[k] = 0;
                count = 0;
                goto here;
            }
        }
        count ++;
        if( count > max )
            max = count;
here:
        p++;
    }
    return max;
}
#endif
int lengthOfLongestSubstring(char *s)
{
    int a[128];
    int i, n;
    int count = 0;
    int max_len = 0;
    int last_position;
    
    memset(a, -1, 128 * sizeof(int));
    n = strlen(s);

    for( i = 0; i < n; i++ )
    {
        last_position = a[s[i]];
        if(last_position != -1)
        {
            i = last_position;
            memset(a, -1, 128 * sizeof(int));
            count = 0;
            continue;
        }
        count ++;
        if( count > max_len )
            max_len = count;
        a[s[i]] = i;
    }
    return max_len;
}

int lengthOfLongestSubstring_best(char *s)
{
    int arr_last_position[127];
    memset(arr_last_position,-1,127*sizeof(int));

    int max_len = 0;
    int count = 0;
    int len = strlen(s);
    int i,last_position;

    int start_point = 0;
    for(i=0; i<len; ++i)
    {
        last_position = arr_last_position[s[i]];
        if(last_position != -1) //repeated char
        {
            if(count>max_len)
                max_len = count;
            if(start_point<=last_position)
            {
                count = i - last_position;
                start_point = last_position + 1;
            }
            else
            {
                count = i - start_point+1;
            }
        }
        else  //single appearance
        {
            count += 1;
        }
        arr_last_position[s[i]] = i;
    }

    if(max_len<count)
        return count;
    else
        return max_len;
}
