#include <stdio.h>
#include<stdlib.h>
int main() {
	int i, T, N, date, *carNum, *fine, totalFine,factor;
	scanf("%d", &T);

    while(T--)
    {       totalFine=0;
        	scanf("%d", &N);
          scanf("%d", &date);
        carNum=(int *)malloc(N*sizeof(int));
        fine=(int *)malloc(N*sizeof(int));
        for(i=0; i<N;i++)
        {
            scanf("%d", &carNum[i]);
        }
         for(i=0; i<N;i++)
        {
            scanf("%d", &fine[i]);
        }
        factor=date%2;
        
        for(i=0; i<N;i++)
        {
            if(carNum[i]%2!=factor)
            {
                totalFine+=fine[i];
                
            }
        }
        
            
        printf("%d\n",totalFine);
        
    }
	return 0;
}
