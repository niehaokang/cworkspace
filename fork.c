/*************************************************************************
	> File Name: fork.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月19日 星期一 10时06分03秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
    char buf[1024] = {0};
    pid_t pid;
    while(1)
    {
        printf("minibash$");
        scanf("%s", buf);
        pid = fork();
        if(pid == 0)
            if(execl(buf, 0) < 0)
                printf("exec error\n");
        else if( pid > 0 )
        {
            int status;
            waitpid(pid, &status, 0);
        }
        else
            printf("fork error %d\n", pid);
    }
    return 0;
}
