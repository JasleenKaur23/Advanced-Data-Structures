#include <stdio.h>
int max(int x, int y)
{
    if(x>=y)
    return x;

    else 
    return y;
    
}

int kadane(int *a, int n)
{
    int global_max, i, curr_max;
    global_max=a[0];
    curr_max=a[0];
    for(i=1;i<n;i++)
    {
        curr_max=max(a[i], curr_max+a[i]);
        global_max=max(curr_max, global_max);
    }
    return global_max;
}



int main() {
	int i,j, T, *a, n, max_sum;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
	    scanf("%d", &n);
	    a= (int *)malloc(n*sizeof(int));
	    for(j=0;j<n;j++)
	    {
	        scanf("%d", &a[j]);
	    }
	    max_sum=kadane(a,n);
	    printf("%d \n", max_sum);
	    
	}
	return 0;
}
