#include<stdio.h>
int a[20],b[20],c[20];
mergeSort(int *a, int *b , int *c , int m, int n )
{
int  i=0;
int j=0;
int k=0;
	while(i<n && j<m && k<m+n)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else 
		{
			c[k]=b[j];
			j++;
			k++;
		}
	}
	if(i>=n)
	{
	while(j<m && k<m+n )
	{
		c[k]=b[j];
		j++;
		k++;
	}
	}
	else if(j>=m)
	{
		while(i<n && k<m+n)
		{	
		c[k]=a[i];
		i++;
		k++;
	}
	}
	printf("Sorted List C is :");
	for(k=0;k<m+n;k++)
	{
		printf("%d  ", c[k]);
	}
	
}
int main()
{
	int i,j,k,n,m;
	
	printf("enter size of A");
	scanf("%d", &n);
	printf("enter the sorted list A");
	for(i=0;i<n;i++)
	{	
	scanf("%d", &a[i]);
	}
	printf("enter size of B");
	scanf("%d", &m);
	printf("enter the sorted list B");
	for(j=0;j<m;j++)
	{	
	scanf("%d", &b[j]);
	}
	
	mergeSort(a,b,c,m,n);
	return 0;
}
