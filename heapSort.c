#include<stdio.h>
int MAX_SIZE;
void heap_sort();

void maxHeapify(int, int);
int arr_sort[20], t, a;

int main() {
  int i;
  printf("Enter the size of array \n");
  scanf("%d",&MAX_SIZE);
  printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
  for (i = 0; i < MAX_SIZE; i++)
    scanf("%d", &arr_sort[i]);

  printf("\nYour Data   :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }

  heap_sort();

  printf("\n\nSorted Data :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }

}
void BuildMaxHeap(arr_sort)
{	int i;
	for ( i = MAX_SIZE / 2 - 1; i >= 0; i--)
    maxHeapify(MAX_SIZE, i);	
}


void heap_sort() {
	int i;
 	BuildMaxHeap(arr_sort);
 /* for ( i = MAX_SIZE / 2 - 1; i >= 0; i--)
    maxHeapify(MAX_SIZE, i);
*/
  for (i = MAX_SIZE - 1; i >= 1; i--) {
    //Swapping Values 
    t = arr_sort[0];
    arr_sort[0] = arr_sort[i];
    arr_sort[i] = t;
    maxHeapify(i, 0);
  }
}

void maxHeapify(int n, int i) {
  int large = i, left = 2 * i+1, right = 2 * i + 2;


  if (left < n && arr_sort[left] > arr_sort[large])
    large = left;


  if (right < n && arr_sort[right] > arr_sort[large])
    large = right;


  if (large != i) {
    //Swapping Values 
    t = arr_sort[i];
    arr_sort[i] = arr_sort[large];
    arr_sort[large] = t;
    maxHeapify(n, large);
  }
}
