/*************************************************************************
	> File Name: lineedit.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月21日 星期五 11时14分49秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int i, j, k;
    int n;
    scanf("%d", &n);
    char s[n][109];
    for ( i = 0; i < n; i++ )
        scanf("%s", s[i]);
    //P#IO#S#CmIJfPBvb@Q#UZS(nm##AWp#Ab#XGVXzydlGxHSvlRi##Q#rXRlti#zawigk(oMgfajkuAvHWDxee#k#Ab#eD#)hWs())
    for ( i = 0; i < n; i++ )
    {
        k = j = 0;
        while( s[i][j] == '#')
            j++;
        while(s[i][j] != '\0')
        {
            if( s[i][j] != '#' && s[i][j] != '@' && s[i][j] != '\0')
                s[i][k++] = s[i][j++];
            if(s[i][j] == '#')
            {
                j++;
                if(k)
                    k--;
            }
            if( s[i][j] == '@' )
            {
                k = 0;
                j++;
            }
        }
        s[i][k] = '\0';
        printf("%s\n", s[i]);
    }
    return 0;
}
