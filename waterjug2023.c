#include<stdio.h>

int jug1=0;
int jug2=0;
int maxJug1;
int maxJug2;
void solution1(int jug1, int jug2, int maxJug1,int maxJug2, int regJug1)
{
int temp;
int count=0;
while(jug1!=regJug1)
{
if(jug1==0)
{
jug1=maxJug1;

printf("Jug 1 is filled\n");
count++;
}
else if(jug2==maxJug2)
{
jug2=0;
printf(" jug 2 is empty\n");
count++;
}
else {
if((maxJug2-jug2)<jug1)
{
temp=maxJug2-jug2;
printf(" pour jug2 full\n");
count++;
}
else 
{
temp=jug1;
printf(" pour jug1 to jug2\n");
count++;
}
jug1=jug1-temp;
jug2=jug2+temp;
}
printf("\noutput after pouring \n");
printf(" %d\n",count);
printf(" %d",jug1);
printf(" %d \n",jug2);
}

}


void solution2(int jug1, int jug2, int maxJug1,int maxJug2, int regJug1)
{
int temp;
int count=0;
printf("\n Solution 2:\n");
while(jug1!=regJug1)
{
if(jug2==0)
{
jug2=maxJug2;

printf("\nJug 2 is filled");
count++;
}
else if(jug1==maxJug1)
{
jug1=0;
printf("\njug 1 is empty");
count++;
}
else {
if((maxJug1-jug1)<jug2)
{
temp=maxJug1-jug1;
printf(" fill remaining part of jug1");
count++;
}
else 
{
temp=jug2;
printf("\npour jug2 to jug1");
count++;
}
jug1=jug1+temp;
jug2=jug2-temp;
}
printf("\noutput after pouring ");
printf(" %d",jug1);
printf(" %d \n",jug2);
printf("No of steps= %d\n",count);
}
}


int main()
{
int regJug1;
printf("enter the quantities of Jug 1 & Jug2 ");
scanf("%d", &maxJug1);
scanf("%d", &maxJug2);
printf("enter the end state of jug1");
scanf("%d",&regJug1);
solution1( jug1,  jug2,  maxJug1, maxJug2,  regJug1);
solution2( jug1,  jug2,  maxJug1, maxJug2,  regJug1);
return 0;
}
