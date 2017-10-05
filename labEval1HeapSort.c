#include<stdio.h>
#include<stdlib.h>
int maxSize=0;
int a[20],temp;
void maxHeapify(int n , int i);
void buildHeap()
{
	int i=0;
	for(i=(maxSize/2-1);i>=0;i--)
	{
		maxHeapify(maxSize,i);
	}
}

void heapSort()
{ 
//printf("enter");
	int i;
 buildHeap();
	for(i=maxSize-1;i>=0;i--)
	{
				temp=a[0];
				a[0]=a[i];
				a[i]=temp;
						maxHeapify(i,0);		
	}
//	printf("exit");
}

void maxHeapify(int n , int i)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if((left<n)&&(a[left]>a[largest]))
	{
		largest=left;
	}
	if((right<n)&&(a[right]>a[largest]))
	{
	  largest=right;
	}
//	printf("largest %d is %d\n", largest, a[largest]);
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
	 maxHeapify(n,largest);
	}	
}



int main()
{
int i,size;
double median;
	
	int choice;
	while(1)
	{
	printf("\nenter the choice \n 1) insert the intial element list\n 2) Display sorted list\n 3) Median Calculation 4) exit\n \n ");
	scanf("%d",&choice);
	switch(choice)
	{
		 case 1: printf("enter the No of Elements to be inserted" );
		 								 scanf("%d",&size);
													//maxSize+=size;
		 									for(i=0;i<size;i++)
											 {
														scanf("%d",&a[maxSize+i]);
												}
												maxSize+=size;
												printf("Entered List of Element");
														for(i=0;i<maxSize;i++)
												{
														printf(" %d --> ",a[i]);
												}
												break;
												
		case 2: 					heapSort();
															for(i=0;i<maxSize;i++)
														{
															printf("  %d -->",a[i]);
															}						
															break;
															
	case 3:     heapSort();
													for(i=0;i<maxSize;i++)
														{
															printf("  %d -->",a[i]);
															}
														if((maxSize%2)==1)
													   {
																int mid=maxSize/2;
																median = a[mid];
														}
														else if ((maxSize%2)==0)
														{
															int mid=maxSize/2;
															median=(float)(a[mid]+a[mid-1])/2;
														}
														printf("\n Median is %0.1f\n", median);
														break;
	
	default:   printf("Invalid Choice");
		
	}
}
	//printf("enter the size of elements");
	//scanf("%d",&maxSize);

	/*int i;
	a[0]=1;
	a[1]=21;
	a[2]=3;
	a[3]=40;
	a[4]=50;
	maxSize=5;
	heapSort();
	for(i=0;i<maxSize;i++)
	{
		printf("  %d -->",a[i]);
	}*/
	return 0;
}

