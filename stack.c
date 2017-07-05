/*************************************************************************
	> File Name: stack.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月29日 星期四 15时44分51秒
 ************************************************************************/

#include<stdio.h>
#include<elf.h>

int main(int argc, char * argv[])
{
    int *p = (int *)argv;
    int i;
    Elf32_auxv_t *aux;

    printf("Argument count: %d\n", *(p-1));
    for( i = 0; i < *(p-1); i++ )
        printf("Argument %d : %s\n", i, (char *)(p+i));

    p += i;
    p++;
    printf("Environment:\n");
    while(*p)
    {
        printf("%s\n", (char *)p);
        p++;
    }

    p++;
    printf("Auxiliary Vectors: \n");
    aux = (Elf32_auxv_t *)p;
    while(aux->a_type != AT_NULL)
    {
        printf("Type: %02d Value: %x\n", aux->a_type, aux->a_un.a_val);
        aux++;
    }

    return 0;
}
