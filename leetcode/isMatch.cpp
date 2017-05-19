/*************************************************************************
	> File Name: isMatch.c
	> Author: Datou_Nie
	> Mail: 
	> Created Time: Wed 29 Mar 2017 10:17:28 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

bool isMatch(char *src, char *des);

int main()
{
    char str1[10] = "aaa";
    char str2[10] = ".*";
    bool b = isMatch(str1, str2);
    if(b)
        cout << "Match" << endl;
    else
        cout << "Not Match" << endl;
    return 0;
}

bool isMatch( char* src, char* dst )
{
    while( *src != '\0' && *src == *dst ) src++, dst++;
    if( *src == '\0' && *dst == '\0' ) return true;
    if( *dst == '*' )
    {
        for( ; *src != '\0'; src++ )
            if( isMatch( src+1, dst+1 ) )
                return true;
    }
    
    return false;
}
#if 0
int isMatch(char* p,char* s)
{
    bool m[128][128];
    memset(m,0,sizeof(m));
    m[0][0] =true;
    
    int pl= strlen(p);
    int sl = strlen(s);
    if (pl>sl)
    {
        return false;
    }
    for (int i=1;i<=sl;i++)
    {
        for (int j=1;j<=pl;j++)    
        {
            if (p[j-1] =='*')
            {
                bool mac = false;
                for (int k = i-1;k>=0;k--)
                {
                    mac = mac||m[k][j-1];
                    if (mac)
                    {
                        break;
                    }
                }
                m[i][j] = mac;
            }
            else
            {
                m[i][j] = m[i-1][j-1]&&(p[j-1]==s[i-1]);
                //cout<<i<<j<<m[i-1][j-1]<<m[i][j]<<(p[j]==s[i])<<endl;
            }
        }
    }
    return m[sl][pl];
}
#endif
