#include<stdio.h>
int insert_sort(int * a, int size)
{
    int i, j;
    int temp;
    for( i = 1; i < size; i++ )
    {
        temp = a[i];
        j = i - 1;
        while( a[j] > temp && j >= 0 )
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    return 0;
}

int main()
{
    int i, j;
    int n, m;
    int temp, result = 0;
    int index = 0;
    scanf("%d %d", &n, &m);
    int a[m];
    for( i = 0; i < m; i++ )
        scanf("%d", &a[i]);
    insert_sort(a, m);
    if( m >= n )
    {
        for( i = m - n, j = n; i < m; i++, j-- )
        {
            temp = j * a[i];
            if( temp > result )
            {
                result = temp;
                index = i;
            }
        }
    }
    else
    {
        for( i = 0, j = m; i < m; i++, j-- )
        {
            temp = j * a[i];
            if( temp > result )
            {
                result = temp;
                index = i;
            }
        }
    }
    printf("%d\n", a[index]);
    return 0;
}
