#include<stdio.h>
#include<stdlib.h>
int lcs (int *a , int n )
{
	int *lis;
	int i, j, max=0;
	lis=(int *)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	{
		lis[i]=1;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if((a[i]>a[j])&& (lis[i]<lis[j]+1))
			{
				lis[i]=lis[j]+1;
	     	}
		}
	}
	for(i=0; i<n; i++)
	{
		if(max < lis[i])
		{
			max=lis[i];
		}
	}
	free(lis);
	return max;	
}


int main()
{
	int *a, n, i,max;
	scanf("%d", &n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);		
	}
	max=lcs(a, n);
	printf("%d", max);
	return 0;
	
}
