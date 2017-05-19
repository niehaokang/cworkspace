#include<stdio.h>
int main()
{
	int i, j;
	int n, m;
	int temp;
	int index;
	int count = 0;
	scanf("%d %d", &n, &m);
	int a[n];
	for( i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for( i = 0; i < n; i++)
	{
		for( j = 0; j < n - i - 1; j++)
		{
			if( a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for( i = 0; i < n; i++)
		printf("%d\n", a[i]);
	j = n - 1;
	while(j >= 0)
	{
		if(a[j] == 0)
			j--;
		else
		{
			temp = m - a[j];
			a[j] = 0;
			if(temp == 0)
			{
				count++;
				continue;
			}
			index = j - 1;
			while( index >= 0)
			{
				if( temp >= a[index])
				{
					temp -= a[index];
					a[index] = 0;
					if(temp == 0)
					{
						count++;
						break;
					}
					index--;
				}
				else
					index--;
			}
			if(temp != 0)
				count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
