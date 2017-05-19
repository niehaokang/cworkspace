#include <unistd.h>  
#include <stdio.h>  
#include <signal.h>  
  
void ouch(int sig)  
{  
    printf("\nOUCH! - I got signal %d\n", sig);  
}  
  
int main()  
{  
    struct sigaction act;  
    act.sa_handler = ouch;  
    //创建空的信号屏蔽字，即不屏蔽任何信息  
    sigemptyset(&act.sa_mask);  
    //使sigaction函数重置为默认行为  
    act.sa_flags = SA_RESETHAND;  
  
    sigaction(SIGINT, &act, 0);  
  
    while(1)  
    {  
        printf("Hello World!\n");  
        sleep(1);  
    }  
    return 0;  
}
