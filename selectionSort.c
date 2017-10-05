#include<stdio.h>
int swap(int *a,int  *b )
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


void selectionSort(int *a , int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(a[j]<a[min])
			{
				min=j;	
			}
		}
			swap(&a[min],&a[i]);
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
