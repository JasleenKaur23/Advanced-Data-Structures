#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node * xorNext;
};
struct Node* XOR(struct Node* prev, struct Node* next )
{
return (struct Node*)((unsigned int) prev ^ (unsigned int) next );
}
void insert(struct Node** headRef, int item)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=item;
	newNode->xorNext=XOR(*headRef,NULL);
	if(*headRef!=NULL)
	{
	struct Node* next=XOR((*headRef)->xorNext,NULL);
	(*headRef)->xorNext=XOR(newNode,next);
	
	}
	*headRef=newNode;
}
void printList(struct Node* headRef)
{
	struct Node * curr=headRef;
	struct Node * prev=NULL;
	struct Node * next;
	while(curr!=NULL)
	{
		printf("%d -->", curr->data);
		next=XOR(prev, curr->xorNext);
		prev=curr;
		curr=next;
		
	}
}
int main()
{
	struct Node* head=NULL;
	int choice,value;
	while(1)
	{
		printf("\nenter your choice:\n1: insert \n2: print List\notherwise: exit()\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the value to be insert: ");
					 scanf("%d", &value);
					 insert(&head,value);
					 break;
			case 2: printList(head);break;
			default : return 0; 
		}	
	}
	/*insert(&head,10);
	insert(&head,30);
	insert(&head,50);
	insert(&head,60);
	printList(head);*/
	return 0;
}


