#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *left;
int data;
struct node *right;
};
void insert();
void search();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void delet(int);
struct node *root=NULL;
void main()
{
int opt,x;
do 
{
 printf("\nMenu-Binary Search Tree");
 printf("\n1.Insertion\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Deletion\n7.Exit");
 printf("\nSelect your option:");
 scanf("%d",&opt);
 
 switch(opt)
 {
 case 1:
 insert();
 break;
 case 2:
 inorder(root);
 break;
 case 3:
 preorder(root);
 break;
 case 4:
 postorder(root);
 break;
 case 5:
 search();
 break;
 case 6:
printf("\nEnter the element to delete:\n");
scanf("%d",&x);
 delet(x);
 break;

 default:
 printf("Exited\n");
 }

}while(opt!=7);
}

void insert()
{
int x;
struct node *ne,*ptr,*ptr1;
ne=(struct node *)malloc(sizeof(struct node));
if(ne==NULL)
{
printf("Insufficient Memory");
return;
}
printf("Enter the data to insert:");
scanf("%d",&x);
ne->left=NULL;
ne->right=NULL;
ne->data=x;
if(root==NULL)
{
root=ne;
return;
}
ptr=root;
while(ptr!=NULL)
{
if(x==ptr->data)
{
printf("Item already exist\n");
return;
}
if(x>ptr->data)
{
ptr1=ptr;
ptr=ptr->right;
}
else
{
ptr1=ptr;
ptr=ptr->left;
}
}
if(ptr==NULL)
{
if(x>ptr1->data)
ptr1->right=ne;
else
ptr1->left=ne;
}
}
void inorder(struct node * ptr)
{
if(ptr!=NULL)
{
inorder(ptr->left);
printf("%d ",ptr->data);
inorder(ptr->right);
}
}

void preorder(struct node * ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node * ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ",ptr->data);
	
	}
}

void search()
{
struct node *ptr;
int x;
ptr=root;
printf("Enter the data to search:");
scanf("%d",&x);	
while(ptr!=NULL)
{
if(ptr->data==x)
{
	printf("Data present\n");
	return;
}
if(x>ptr->data)
ptr=ptr->right;
else
ptr=ptr->left;
}
if(ptr==NULL)
printf("Data not present\n");
}

void delet(int x)
{
	struct node *ptr,*parent,*p;
int dat;
if(root==NULL)
{
	printf("Tree is empty");
	return;
	}	
	parent=NULL;
	ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->data==x)
		break;
		parent=ptr;
		if(x>ptr->data)
		ptr=ptr->right;
		else
		ptr=ptr->left;
	}
	if(ptr==NULL)
	{
		printf("Item not present");
		return;
	}
	if(ptr->right==NULL && ptr->left==NULL)
	{
		if(parent==NULL)
		root=NULL;
		else if(parent->right==ptr)
		parent->right=NULL;
		else
		parent->left=NULL;
		printf("Element deleted");
		free(ptr);
		return;
	}
	if(ptr->right!=NULL && ptr->left!=NULL)
	{
		p=ptr->right;
		while(p->left!=NULL)
		{
			p=p->left;
		}
		dat=p->data;
		delet(p->data);
		ptr->data=dat;
		return;
	}
	if(parent==NULL)
	{
		if(ptr->right==NULL)
		root=ptr->left;
		else
		root=ptr->right;
	}
	else 
	{
		if(parent->right==ptr)
		{
			if(ptr->right==NULL)
			parent->right=ptr->left;
			else
			parent->right=ptr->right;
		}
		else
		{
			if(ptr->left==NULL)
			parent->left=ptr->right;
			else
			parent->left=ptr->left;
		}
	}
printf("\nElement deleted");
free(ptr);
return;	
}
