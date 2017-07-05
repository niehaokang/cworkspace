/*************************************************************************
	> File Name: strcpy.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月04日 星期二 20时18分15秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

char * strcopy(char *dest, const char *src); 
char * mystrcpy( char *dest, const char *src );
char * glibcstrcpy( char *dest, const char *src );

int main()
{
    char str[11] = "abcdefg";
    cout << glibcstrcpy( str + 2, str ) << endl;
    cout << str << endl;
    return 0;
}

char * strcopy(char *dest, const char *src)
{
    return (char *)memmove(dest, src, strlen(src) + 1);
}

char * mystrcpy( char *dest, const char *src )
{
    if( (NULL == dest) || (NULL == src) )
        cout << "invalid_argument" << endl;
    int len = strlen(src);
    char *strdestcopy = dest;
    if( dest >= src )
    {
        while( len >= 0 )
        {
            *(dest + len) = *(src + len);
            len--;
        }
    }
    else
    {
        int i = 0;
        while( i <= len )
        {
            *(dest + i) = *(src + i);
            i++;
        }
    }
    return strdestcopy;
}

char * glibcstrcpy( char * dest, const char * src )
{
    char c;
    char *s =  (char *)src;
    const ptrdiff_t off = dest - s - 1;
    cout << off << endl;
    do{
        c = *s ++;
        s[off] = c;
    } while( c !='\0' );
    return dest;
}
