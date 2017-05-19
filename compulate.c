/*************************************************************************
	> File Name: compulate.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年05月18日 19:19:19
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<math.h>

int compulate(char *s);
//int operator(int operand_a, int operand_b, int operator_code);

int main()
{
    char s[200];
    while(scanf("%s", s) != EOF)
    {
        printf("%s\n", s);
        printf("%d\n", compulate(s));
    }
    return 0;
}


int compulate(char *s)
{
    printf("%s\n", s);
    int operand_a;
    int operand_b;
    int op_top = 0;
    int operand_top = 0;
    char op[200];
    int operand[200];
    memset(op, 0, 200 * sizeof(char));
    memset(operand, 0, 200 * sizeof(int));
    while(*s != '\0')
    {
        if( *s >= '0' && *s <= '9')
        {
//            while( *s >= '0' && *s <= '9')
//            {
                //operand[operand_top] += operand[operand_top] * 10 + (*s - '0');
                operand[operand_top++] = *s - '0';
//            }
        }
        else if(*s == '+' || *s == '-')
        {
            if( op_top == 0)
                op[op_top++] = *s;
            else if( op[op_top] == '+' || op[op_top] == '-')
            {
                operand_b = operand[--operand_top];
                operand_a = operand[--operand_top];
                if( op[op_top--] == '+')
                    operand[operand_top++] = operand_a + operand_b;
                else
                    operand[operand_top++] = operand_a - operand_b;
                op[op_top++] = *s;
            }
            /*
            else if( op[op_top] == '*' || op[op_top] == '/')
            {
                operand_b = operand[--operand_top];
                operand_a = operand[--operand_top];
                if( op[op_top--] == '+')
                    operand[operand_top++] = operand_a + operand_b;
                else
                    operand[operand_top++] = operand_a - operand_b;
                op[op_top++] = *s;
            }
            else if( op[op_top] == '^')
            {
                operand_b = operand[--operand_top];
                operand_a = operand[--operand_top];
                operand[operand_top++] = pow(operand_a, operand_b);
                op[op_top++] = *s;
            }
            */
        }
        /*
        else if( *s == '*' || *s == '/')
        {
            if(op_top == 0)
                op[op_top++] = *s;
            else if( op[op_top] == '*' || op[op_top] == '/')
            {
                operand_b = operand[--operand_top];
                operand_a = operand[--operand_top];
                if( op[op_top--] == '+')
                    operand[operand_top++] = operand_a + operand_b;
                else
                    operand[operand_top++] = operand_a - operand_b;
                op[op_top++] = *s;
            }
            else if( op[op_top] == '^')
            {
                operand_b = operand[--operand_top];
                operand_a = operand[--operand_top];
                operand[operand_top++] = pow(operand_a, operand_b);
                op[op_top++] = *s;
            }
        }
        else if( *s = '^')
        {
            op[op_top++] = *s;
        }
        else if( *s == '(')
        {
            op[op_top++] = *s;
        }
        else if( *s = ')')
        {
            if(op[op_top] == '*' || op[op_top] == '/')
            {
                operand_b = operand[--operand_top];
                operand_a = operand[--operand_top];
                if(op[op_top--] == '*')
                    operand[operand_top++] = operand_b * operand_a;
                else
                    operand[operand_top++] = operand_a / operand_b;
                if( op[op_top] == '+' || op[op_top] == '-')
                {
                    operand_b = operand[--operand_top];
                    operand_a = operand[--operand_top];
                    if(op[op_top--] == '+')
                        operand[operand_top++] = operand_b + operand_a;
                    else
                        operand[operand_top++] = operand_a - operand_b;
                }
                op_top--;
            }
            else if( op[op_top] == '+' || op[op_top] == '-')
            {
                operand_b = operand[--operand_top];
                operand_a = operand[--operand_top];
                if(op[op_top--] == '+')
                    operand[operand_top++] = operand_b + operand_a;
                else
                    operand[operand_top++] = operand_a - operand_b;
                op_top--;
            }
        }
        */
        s++;
    }
    while(op_top != 0)
    {
        if( op[op_top] == '+' || op[op_top] == '-')
        {
                operand_b = operand[--operand_top];
                operand_a = operand[--operand_top];
                if(op[op_top--] == '+')
                    operand[operand_top++] = operand_b + operand_a;
                else
                    operand[operand_top++] = operand_a - operand_b;
                op_top--;
        }
        
    }
    return operand[0];
}
/*
int operator(int operand_a, int operand_b, int operator_code)
{
    switch( operator_code )
    {
        case 0:
        return operand_a + operand_b;
        break;
        case 1:
        return operand_a - operand_b;
        break;
        case 2:
        return operand_a * operand_b;
        break;
        case 3:
        return operand_a / operand_b;
        break;
        case 4:
        return (int) pow(operand_a, operand_b);
        break;
    }
}
*/
