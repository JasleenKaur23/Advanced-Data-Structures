#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node* left;
struct Node* right;
int height;	
};

/* function to create a new NOde*/

// A utility function to get height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}


// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* newNode(int item)
{
	struct Node* new= (struct Node*)malloc(sizeof(struct Node));
	new->data=item;
	new->left=NULL;
	new->right=NULL;
	new->height=1;
	return (new);
	
}

struct Node* llRotation(struct Node* parent)
{
  struct Node* temp=parent->left;
  parent->left=temp->right;
  temp->right=parent;
  parent->height=max(height(parent->left), height(parent->right))+1;
  temp->height=max(height(temp->left), height(temp->right))+1;
  
  return temp;
}


struct Node* rrRotation(struct Node* parent)
{
  struct Node* temp=parent->right;
  parent->right=temp->left;
  temp->left=parent;
  parent->height=max(height(parent->left), height(parent->right))+1;
  temp->height=max(height(temp->left), height(temp->right))+1;
  
  return temp;
}

struct Node * lrRotation(struct Node* parent)
{
	struct Node* temp=parent->left;
	parent->left = rrRotation(temp);
	return llRotation(parent);
}


struct Node * rlRotation(struct Node* parent)
{
	struct Node* temp=parent->right;
	parent->right = llRotation(temp);
	return rrRotation(parent);
}



struct Node* insert(struct Node * parent, int item)
{
	if(parent==NULL)
	{
		parent=newNode(item);
		return parent;
	}
	if(item<parent->data)
	{
		parent->left=insert(parent->left,item);
	}
	else if (item>parent->data)
	{
		parent->right=insert(parent->right,item);
	}
	/* Equal keys are not allowed*/
	else 
	return parent;
	
	 parent->height = 1 + max(height(parent->left),
                           height(parent->right));
 
 	int balance = getBalance(parent);
 	
 	if (balance > 1 && item < parent->left->data)
        return llRotation(parent);
 
    // Right Right Case
    if (balance < -1 && item > parent->right->data)
        return rrRotation(parent);
 
    // Left Right Case
    if (balance > 1 && item > parent->left->data)
    {
       // node->left =  leftRotate(node->left);
        return lrRotation(parent);
    }
 
    // Right Left Case
    if (balance < -1 && item < parent->right->data)
    {
        //node->right = rightRotate(node->right);
        return rlRotation(parent);
    }
 
    /* return the (unchanged) node pointer */
    return parent;
	
	
}


void preOrder(struct Node* root)
{
	if(root!=NULL)
	{
		printf("%d   ", root->data);
		preOrder(root->left);
		
		preOrder(root->right);
		
	}
}


int main()
{
	struct Node* root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);
	root=insert(root,25);
	preOrder(root);
	return 0;
}







