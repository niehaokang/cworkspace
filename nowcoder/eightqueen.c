/*************************************************************************
	> File Name: eightqueen.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月05日 星期三 08时22分28秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

void eightqueen(int i);
void print();
int is_valid_position(int index, int value);

int queenindex[8];
int count = 0;
int total_judge = 0;

int main()
{
    memset( queenindex, 0, sizeof(queenindex));
    eightqueen(0);
    printf("total_judge = %d, count = %d\n", total_judge, count);
    return 0;
}

void print()
{
    int i, j;
    for( i = 0; i < 8; i++ )
    {
        for( j = 0; j < queenindex[i]; j++)
            printf("*");
        
        printf("#");

        for( j = queenindex[i] + 1; j < 8; j++ )
            printf("*");
        printf("\n");
    }
    printf("-----------------------\n");
}

int is_valid_position(int index, int value)
{
    total_judge++;
    int i;
    for( i = 0; i < index; i++ )
    {
        if( value == queenindex[i] )
            return 0;
        if( index - i == value - queenindex[i] )
            return 0;
        if( index - i == queenindex[i] - value )
            return 0;
    }
    return 1;
}

void eightqueen( int i )
{
    int j;
    for( j = 0; j < 8; j++ )
    {
        if( is_valid_position(i, j) )
        {
            queenindex[i] = j;
            if( 7 == i )
            {
                count++;
                print();
                return;
            }
            eightqueen( i + 1 );
            queenindex[i] = 0;
        }
    }
}
