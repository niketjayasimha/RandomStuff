#include <stdio.h>
void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int choose_pivot(int i,int j )
{
	return((i+j) /2);
}

void quicksort(int list[],int m,int n)
{
	int key,i,j,k;
	if( m < n)
	{
		k = choose_pivot(m,n);
		swap(&list[m],&list[k]);
		key = list[m];
		i = m+1;
		j = n;
		while(i <= j)
		{
			while((i <= n) && (list[i] <= key))
				i++;
			while((j >= m) && (list[j] > key))
				j--;
			if( i < j)
				swap(&list[i],&list[j]);
		}
		// swap two elements
		swap(&list[m],&list[j]);
		// recursively sort the lesser list
		quicksort(list,m,j-1);
		quicksort(list,j+1,n);
	}
}
int search(int a[], int val, int n)
{
	int lb = 0;
	int ub = n-1;
	int pos = -1;
	int mid;
	while(pos == -1 && (ub >= lb))
	{
		mid = (ub+lb)/2;
		if(a[mid] == val)
			pos = mid;
		if(a[mid] < val)
			lb = mid + 1;
		else
			ub = mid - 1;
	}
	return pos;
}
int main()
{
	int x[101];
	int a[101];
	int i,t,j,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
			a[i]=x[i];
		}
		quicksort(a,0,n-1);
		printf("%d\n",search(x,a[n-1],n));
	}
	return 0;
}
