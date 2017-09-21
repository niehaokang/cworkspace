/*************************************************************************
	> File Name: mystrcpy.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月20日 星期三 15时41分29秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

char *mystrcpy( char *dest, const char * src )
{
    if( dest == NULL || src == NULL )
        return NULL;
    else if( dest == src )
        return dest;
    int i = 0;
    if( dest > src )
    {
        while( src[i] != '\0' )
            i++;
        while( i >= 0 )
        {
            dest[i] = src[i];
            i--;
        }
    }
    else
    {
        while( src[i] != '\0' )
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return dest;
}

int main()
{
    char src[20] = "Hello World!";
    char mysrc[20] = "Hello World!";
    cout << strcpy(src + 3, src ) << endl;
    cout << src << endl;
    cout << mystrcpy( mysrc + 3, mysrc ) << endl;
    cout << mysrc << endl;
    return 0;
}
