#include<stdio.h>
int swap(int *a,int  *b )
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


void bubbleSort(int *a , int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j+1]<a[j])
			{
				swap(&a[j],&a[j+1]);
			}
		}
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

	bubbleSort(a, n);

	return 0;
	
}
