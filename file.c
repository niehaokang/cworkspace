/*************************************************************************
	> File Name: file.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月08日 星期一 22时08分04秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fd;
    fd = fopen("/home/nie/cworkspace/file.txt", "rw");
    fwrite("Hello, niehaokang.", 1, strlen("Hello, niehaokang."), fd);
    char buf[strlen("Hello, niehaokang") + 1];
    fclose(fd);
    fd = fopen("/home/nie/cworkspace/file.txt", "r");
    rewind(fd);
    fread(buf, 1, strlen("Hello, niehaokang"), fd);
    buf[strlen("Hello, niehaokang")] = '\0';
    printf("%s\n", buf);
    fclose(fd);
    return 0;
}
