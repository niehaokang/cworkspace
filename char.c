/*************************************************************************
	> File Name: char.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月18日 星期日 13时25分42秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

char firstnotrepeatingchar(const char *str);

char * removecharappearinremove(char * src, const char * remove);

char * duplicateremove(char *src);

int anagram(const char * stra, const char * strb);

void replacespecialcharacters(char s[], int length);

int main()
{
    /*
    const char *m = "hello world!";
    const char *n = "hello world!";
    printf("%p\n", m);
    printf("%p\n", n);
    const char mm[] = "hello world!";
    const char nn[] = "hello world!";
    printf("m = n ?: %d\n",(int)( mm == nn));
    printf("%c\n", firstnotrepeatingchar("nuull"));
    char src[20] = "We are students.";
    char remove[10] = "aeiou";
    char str[10] = "google";
    char stra[20] = "silent";
    char strb[20] = "listen";
    printf("%s\n", removecharappearinremove(src, remove));
    printf("%s\n", duplicateremove(str));
    printf("%d\n", anagram(stra, strb));
    */
    char url[30] = "we are()students#";
    replacespecialcharacters(url, 30);
    printf("%s", url);
    return 0;
}

char firstnotrepeatingchar(const char *str)
{
    int i = 0;
    if( str == NULL )
        return '\0';
    int hashtable[256];
    memset(hashtable, 0, sizeof(hashtable));
    const char *s = str;
    while( *(s+i) != '\0')
    {
        hashtable[*(s+i)]++;
        i++;
    }
    i = 0;
    while( *(s+i) != '\0')
    {
        if(hashtable[*(s+i)] == 1)
            return *(s + i);
        i++;
    }
    return '\0';
}

char * removecharappearinremove(char * src, const char * remove)
{
    if(src == NULL || remove == NULL)
        return src;
    int i;
    int rlen = strlen(remove);
    int slen = strlen(src);
    int hashtable[256];
    memset(hashtable, 0, sizeof(hashtable));
    char *ahead, *behind;
    for( i = 0; i < rlen; i++)
        hashtable[*(remove + i)] = 1;
    ahead = behind = src;
    for( i = 0; i < slen; i++)
    {
        if( hashtable[*ahead] == 1)
            ahead++;
        else
        {
            *behind = *ahead;
            behind++;
            ahead++;
        }
    }
    *behind = '\0';
    return src;
}

char * duplicateremove(char *src)
{
    if(src == NULL)
        return '\0';
    int len = strlen(src);
    int i;
    int hashtable[256];
    char *ahead, *behind;
    memset(hashtable, 0, sizeof(hashtable));
    ahead = behind = src;
    for( i = 0; i < len; i++ )
    {
        if( hashtable[*(src + i)] == 1 )
            ahead++;
        else
        {
            hashtable[*ahead] = 1;
            *(behind++) = *(ahead++);
        }
    }
    *behind = '\0';
    return src;
}

int anagram(const char * stra, const char * strb)
{
    if( stra == NULL || strb == NULL )
        return 0;
    if( strlen(stra) != strlen(strb) )
        return 0;
    int i;
    int hashtable[256];
    memset(hashtable, 0, sizeof(hashtable));
    while( *stra != '\0' )
    {
        hashtable[*stra] += 1;
        stra++;
    }
    while(*strb != '\0')
    {
        hashtable[*strb] -= 1;
        strb++;
    }
    for( i = 0; i < 256; i++ )
        if(hashtable[i] != 0)
            return 0;
    return 1;
}

void replacespecialcharacters(char s[], int length)
{
    if( s == NULL )
        return;
    char *p = s;
    int originallength = strlen(s);
    int newlength = 0;
    int numspecialchar = 0;
    while( *p != '\0'  )
    {
        if(*p == '(' || *p == ')'|| *p == '#' || *p == ' ')
            numspecialchar++;
        p++;
    }
    newlength = originallength + numspecialchar * 2;
    if( newlength >= length )
        return;
    int indexoforiginal = originallength;
    int indexofnew = newlength;
    while( indexoforiginal >= 0 && indexofnew > indexoforiginal )
    {
        char c = s[indexoforiginal];
        if( c == '(' )
        {
            s[indexofnew--] = '8';
            s[indexofnew--] = '2';
            s[indexofnew--] = '%';
        }
        else if( c == ')' )
        {
            s[indexofnew--] = '9';
            s[indexofnew--] = '2';
            s[indexofnew--] = '%';
        }
        else if( c == ' ' )
        {
            s[indexofnew--] = '0';
            s[indexofnew--] = '2';
            s[indexofnew--] = '%';
        }
        else if( c == '#' )
        {
            s[indexofnew--] = '3';
            s[indexofnew--] = '2';
            s[indexofnew--] = '%';
        }
        else
            s[indexofnew--] = s[indexoforiginal];
        indexoforiginal--;
    }
}
