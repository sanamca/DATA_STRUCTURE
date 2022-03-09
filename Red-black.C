#include<stdio.h>
#include<stdlib.h>
#define red  1
#define black 0
struct node
{   int data,color;
    struct node *right,*left;
} ;
void doop(struct node *,struct node *,struct node *);
void RRRotation(struct node *);
void LLRotation(struct node *);
void inorder(struct node *ptr);
void insert();
void doop(struct node *ne,struct node *parent,struct node *pparent);


struct node *ROOT=NULL;
struct node* findParent(struct node *n)  ;


//function to reserve memory for a node
struct node * getNode()
{
    struct node *ne;
    ne=(struct node *) malloc(sizeof(struct node));
    if (ne==NULL)
       printf("No Memory");
    return ne;
}


//function to find the parent node of a node
struct node* findParent(struct node *n)
{   struct node *ptr=ROOT,*parent=NULL;
     int x=n->data;
   while(ptr!=n)
       {   parent=ptr;
	  if (x>ptr->data)
	      ptr=ptr->right;
	   else
	     ptr=ptr->left;
	}
    return parent;
}




int main()
{
int ch;
do{
	printf("\nMenu");
    printf("\n1.Insert\n2.display\n3.Exit\nEnter Your choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {  case 1:insert();
	       break;
       case 2:inorder(ROOT);
		break;
    }
  }while(ch!=3);
}






//function for inorder traversal
void inorder(struct node *ptr)
{  if (ptr!=NULL)
   {   inorder(ptr->left);
       printf("%d(%c)  ",ptr->data,ptr->color==0?'b':'r');
       inorder(ptr->right);
    }
}

//function to insert a value in the Binary search tree
void insert()
{  int x;
   struct node *ne,*parent,*ptr,*pparent,*uncle;
//Perform standard BST insertion and make the colour of newly inserted nodes as RED.
   printf("Enter the element to insert:\n");
   scanf("%d",&x);
   ne=getNode();
   if (ne==NULL)
      return;
   ne->data=x;
   ne->left=ne->right=NULL;
   ne->color=red;
//If x is the root, change the colour of x as BLACK and return
   if (ROOT==NULL)
     { ROOT=ne;
	ne->color=black;
	return;
     }
   ptr=ROOT;
   while(ptr!=NULL)
   {   if (ptr->data==x)
	{   printf("Data already present");
	    break;
	}
	parent=ptr;
	if (x>ptr->data)
	   ptr=ptr->right;
	else
	  ptr=ptr->left;
   }
   if (ptr!=NULL)
       return;
  if(x>parent->data)
      parent->right=ne;
  else
    parent->left=ne;
  while(ne!=ROOT)
  {      //find uncle
	parent=findParent(ne);
	if (parent->color==black)
	     break;
	if (parent->color==red)
	{
	  pparent=findParent(parent);
	if (pparent->right==parent)
	   uncle=pparent->left;
	else
	  uncle=pparent->right;
//If x’s uncle is BLACK, or NULL then call doop()

       if (uncle==NULL)
	{    	doop(ne,parent,pparent);
		break;
	}
       if (uncle->color==black )
	  {	doop(ne,parent,pparent);
		break;
	}
  /* If x’s uncle is RED (Grandparent must have been black from property 4) 
(1)Change the colour of parent and uncle as BLACK. 
(ii) Colour of a grandparent as RED. 
(iii) Change x = x’s grandparent, repeat steps 2 and 3 for new x. */

       if (uncle->color==red)
	  {	parent->color=uncle->color=black;

		if (pparent!=ROOT)
		{  if (pparent->color==red)
			pparent->color=black;
		   else
			pparent->color=red;
		   if(pparent->color==red)
			 ne=pparent;

		}
		else
				break;
	  }

}

 }

  }

void doop(struct node *ne,struct node *parent,struct node *pparent)
{	/*(i) Left Left Case (p is left child of g and x is left child of p) 
	(ii) Left Right Case (p is left child of g and x is the right child of p) 
	(iii) Right Right Case (Mirror of case i) 
	(iv) Right Left Case (Mirror of case ii)*/
	
	if(ne==parent->left && parent==pparent->left)
	{     struct node *left=pparent->left;
	      LLRotation(pparent);
	      parent->color=parent->color==1?0:1;
	      pparent->color=pparent->color==1?0:1;
		if (pparent==ROOT)
		   ROOT=left;

	}

	  else if (parent==pparent->left && ne==parent->right)
	   {  struct node *left=parent->right;
		RRRotation(parent);
	     LLRotation(pparent);
	    ne->color=ne->color==1?0:1   ;
	    pparent->color=pparent->color==1?0:1;
		if (pparent==ROOT)
		   ROOT=left;

	    }
	  else if ( ne==parent->right && parent==pparent->right)
	  {     struct node *right=pparent->right;
		RRRotation(pparent);
		parent->color=parent->color==0?1:0;
		pparent->color=pparent->color==0?1:0;
		if (pparent==ROOT)
		   ROOT=right;
		}
	     else if (parent==pparent->right && ne==parent->left)
		{  struct node *left=parent->left;
		   LLRotation(parent);
		  RRRotation(pparent);
		  pparent->color=pparent->color==1?0:1;
		  ne->color=ne->color==1?0:1;
		if (pparent==ROOT)
		   ROOT=left;
			}
 }
 void LLRotation(struct node *y) // function for Right Rotation
 {     struct node *p=findParent(y);
       struct node *x=y->left;
       struct node *T2= x->right;
       if (x!=NULL)
	x->right=y;
	y->left=T2;
	if (p!=NULL)
	if (p->right==y)
	   p->right=x;
	else
	  p->left=x;

 }
void RRRotation(struct node *x)  // function for left rotation
{ struct node *p=findParent(x);
struct node *y=x->right;
struct node *T2=y->left;
if (y!=NULL)
y->left=x;
x->right=T2;
if (p!=NULL)
if (p->right==x)
  p->right=y;
else
  p->left=y;
}





