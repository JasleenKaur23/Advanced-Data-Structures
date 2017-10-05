#include<stdio.h>
void selectionSort(int *a , int n)
{
	int i,j,temp;
	for(i=1;i<n-1;i++)
	{
		temp=a[i];
		j=i-1;
		while(a[j]>temp && j>=0)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n", a[i]);
	}

}

int main()
{
	int i;
	int n=10;
	int a[10]={5,6,4,3,2,1,0,45,34,36};

	selectionSort(a, n);

	return 0;
	
}
