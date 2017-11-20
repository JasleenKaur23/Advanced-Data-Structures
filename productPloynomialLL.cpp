#include<iostream>
#include<conio.h>
#include<process.h>
#include<stdio.h>
using namespace std;
class link
{
 public:
 int coff,order;
 link *next;
 void getd(int a)
 {
 cout<<"enter the coff:";
 cin>>coff;
 order=a;
 next=NULL;
 }
 void showd()
 {
 cout<<coff<<"*"<<"X^"<<order;
 }
 };//end of class
 link *start1=NULL,*start2=NULL,*start3=NULL,*ptr,*ptr1,*newptr;
 void enter(int or1 ,int or2)
 {
 int i;
for(i=or1;i>=0;i--) //entry for poly1
{
cout<<"enter coff for X^"<<i<<":";
newptr=new link;
 newptr->getd(i);
 if(start1==NULL)
 start1=newptr;
 else
 {
ptr=start1;
while(ptr->next!=NULL)
	 ptr=ptr->next;
	ptr->next=newptr;
 }
}
 for( i=or2;i>=0;i--)//entry for poly2
{
cout<<"enter coff for X^"<<i<<":";
newptr=new link;
 newptr->getd(i);
 if(start2==NULL)
 start2=newptr;
 else
 {
ptr=start2;
while(ptr->next!=NULL)
	 ptr=ptr->next;
	ptr->next=newptr;
 }
}
 }
 void mult()
 {
int order,coff;
link *ptr3;
if(start1==NULL)
{
cout<<"multiplication not possible";
//exit(0);
}
ptr=start1;
while(ptr!=NULL)//traversing list 1
{
if(start2!=NULL)
{
 ptr1=start2;
 while(ptr1!=NULL) //traversing list 2
 {
	newptr=new link;
	newptr->coff=ptr->coff*ptr1->coff;
	newptr->order=ptr->order+ptr1->order;
	 newptr->next=NULL;
	 if(start3==NULL)
	 start3=newptr;
	else
	 {
	 ptr3=start3;
	 while(ptr3->next!=NULL)
	ptr3=ptr3->next;
	 ptr3->next=newptr;
	 }
 ptr1=ptr1->next;
 }//traversing list 2 complete
}
ptr=ptr->next;
 } //traversing list 1 complete
ptr=start3; //combining similar order terms
while(ptr->next!=NULL)
{ ptr1=ptr;
 while(ptr1->next!=NULL)
 {
ptr3=ptr1;
	ptr1=ptr1->next;
if(ptr->order==ptr1->order)
	{
	ptr->coff=ptr->coff + ptr1->coff;
ptr3->next=ptr1->next;
delete ptr1;
ptr1=ptr3;
}
 }
 ptr=ptr->next;
}
 }
 void showall()//output of polynomials
 {
ptr=start1;
cout<<endl<<endl;
while(ptr!=NULL)
{
ptr->showd();
ptr=ptr->next;
if(ptr!=NULL) cout<<" + ";
 }
 ptr=start2;
cout<<endl<<endl;
while(ptr!=NULL)
{
ptr->showd();
ptr=ptr->next;
if(ptr!=NULL) cout<<" + ";
 }
ptr=start3;
cout<<endl<<endl;
while(ptr!=NULL)
{
ptr->showd();
ptr=ptr->next;
if(ptr!=NULL) cout<<" + ";
 }
 }
 //link *start1=NULL,*start2=NULL,*ptr,*newptr; //all are pointing at null
int  main()
 {
 int o1,o2;
// clrscr();
 cout<<"enter the order of polynomial 1:";
 cin>>o1;
 cout<<"\nenter the order of polynomial 2:";
 cin>>o2;
 enter(o1,o2);
 mult();
 showall();
 getch();
 return 0;
 }
