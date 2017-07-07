/*************************************************************************
	> File Name: replaceblank.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月06日 星期四 10时19分57秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

char * replaceblank(char *dest, char *src);

int main(int argc, char *argv[])
{
    char src[20] = "we are happy.";
    char dest[50] = "";
    replaceblank(dest, src);
    printf("%s", dest);
    return 0;
}

char * replaceblank( char *dest , char * src)
{
    if( src == NULL || strlen(src) == 0 )
        return 0;
    int i;
    int srclen = strlen(src);
    int destlen = srclen;
    for( i = 0; i < srclen; i++ )
        if( src[i] == ' ' )
            destlen += 2;
    printf("%d %d\n", srclen, destlen);
    dest[destlen] = '\0';
    while( srclen >= 0 )
    {
        if( src[srclen] == ' ' )
        {
            dest[destlen--] = '0';
            dest[destlen--] = '2';
            dest[destlen--] = '%';
        }
        else
            dest[destlen--] = src[srclen];
        srclen--;
    }
    return dest;
}
