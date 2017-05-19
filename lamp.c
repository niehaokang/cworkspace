#include<stdio.h>
void inner_fast_sort(int *a, int left, int right)
{
        if( left >= right  )
            return;
        int i = left, j = right;
        int temp = a[left];

        while( i < j  )
    {
                for( ; i < j && a[j] > temp; j--  );
                a[i] = a[j];

                for( ; i < j && a[i] < temp; i++  );
                a[j] = a[i];
            
    }
        a[i] = temp;
        inner_fast_sort(a, left, i - 1);
        inner_fast_sort(a, i + 1, right);

}

int fast_sort(int * a, int size)
{
        inner_fast_sort(a, 0, size - 1);
        return 0;

}
int main()
{
      int n, l;
      int i;
    double temp = 0;
      scanf("%d %d", &n, &l);
      int a[n];
      for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
      fast_sort(a, n);
    temp = (double)a[0];
    for(i = 1; i < n; i ++)
    {
        if( a[i] - a[i-1] > 2 * temp )
              temp = (a[i] - a[i-1])/2.0;
    }
    if( l - a[i - 1] > temp )
        temp = l - a[i-1];
      printf("%.2f", temp);

}
