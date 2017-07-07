/*************************************************************************
	> File Name: find_array.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月05日 星期三 21时51分47秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int find_array( int *a, int rows, int cols, int num );
int main(int argc, char *argv[])
{
    int i, j;
    int num;
    int a[4][4] = {
        { 1, 2, 8, 9 },
        { 2, 4, 9, 12 },
        { 4, 7, 10, 13 },
        { 6, 8, 11, 15 },
    };
    for( i = 0; i < 4; i++ )
    {
        for( j = 0; j < 4; j++ )
            printf("%d ", a[i][j]);
        printf("\n");
    }
    num = atoi(argv[1]);
    printf("%d\n", find_array(&a[0][0], 4, 4, num));
    return 0;
}

int find_array( int *a, int rows, int cols,  int num )
{
    int row = 0, col = cols - 1;
    if( a == NULL )
        return 0;
    if( num < a[0] || num > a[rows * cols - 1] )
        return 0;
    while( row < rows && col >= 0 )
    {
        if( a[row * cols + col] == num )
        {
            printf("a[%d] = %d\n", row * cols + col, a[row * cols + col]);
            return 1;
        }
        else if ( a[row * cols + col] > num )
            col--;
        else
            row++;
    }
    return 1;
}
