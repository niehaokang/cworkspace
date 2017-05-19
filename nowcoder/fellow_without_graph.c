/*************************************************************************
	> File Name: fellow.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月11日 星期四 21时07分54秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    int k = 0;
    int cnt[10];
    while(1)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if( a == 0 && b == 0 )
            break;
        int i;
        int temp;
        int fellow[b][3];
        int queue[a + 1];
        int index[a + 1];
        int count = 0;
        int head, tail;
        head = 0; tail = 0;
        memset(index, 0, (a + 1) * sizeof(int));
        memset(fellow, 0, b * 3 * sizeof(int));
        for( i = 0; i < b; i++ )
            scanf("%d %d", &fellow[i][0], &fellow[i][1]);
        index[1] = 1;
        for( i = 0; i < b; i++ )
        {
            if( fellow[i][0] == 1 )
            {
                queue[tail++] = fellow[i][1];
                fellow[i][2] = 1;
                count++;
                index[fellow[i][1]] = 1; 
            }
            else if( fellow[i][1] == 1 )
            {
                queue[tail++] = fellow[i][0];
                fellow[i][2] = 1;
                count++;
                index[fellow[i][0]] = 1; 
            }
        }
        while( tail != head )
        {
            temp = queue[head++];
            for( i = 0; i < b; i++ )
            {
                if( fellow[i][2] == 1 )
                    continue;
                else
                {
                    if( fellow[i][0] == temp )
                    {
                        fellow[i][2] = 1;
                        if( index[fellow[i][1]] == 0 )
                        {
                            queue[tail++] = fellow[i][1];
                            index[fellow[i][1]] = 1;
                            count++;
                        }
                    }
                    else if( fellow[i][1] == temp )
                    {
                        fellow[i][2] = 1;
                        if( index[fellow[i][0]] == 0 )
                        {
                            queue[tail++] = fellow[i][0];
                            index[fellow[i][0]] = 1;
                            count++;
                        }
                    }
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
