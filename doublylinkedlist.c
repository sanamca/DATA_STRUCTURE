#include<stdlib.h>
#include<stdio.h>
void insert_first();
void insert_last();
void insert_pos();
void delete_first();
void delete_last();
void delete_pos();
void search();
void display();
struct node
{
struct node *left;
int data;
struct node *right;
};
struct node *head=NULL;
void main()
{
int opt;
do 
{
 printf("\nMenu");
 printf("\n1.Insert At First\n2.Insert At Last\n3.Search\n4.display\n5.Delete First\n6.Delete Last\n7.Insert at position\n8.Delete At Position\n9.Exit");
 printf("\nSelect your option:");
 scanf("%d",&opt);
 switch(opt)
 {
 case 1:
 insert_first();
 break;
 case 2:
 insert_last();
 break;
 case 3:
 search();
 break;
 case 4:
 display();
 break;
 case 5:
 delete_first();
 break;
 case 6:
 delete_last();
 break;
 case 7:
 insert_pos();
 break;
 case 8:
 delete_pos();
 break;
 default:
 printf("Exited");
 }
}while(opt!=9);
}


void insert_first()
{
int x;
struct node *ne;
ne=(struct node *)malloc(sizeof(struct node));
if(ne==NULL)
printf("Insufficient Memory");
else
{
printf("\nEnter the data to insert\n");
scanf("%d",&x);
ne->data=x;
ne->left=NULL;
ne->right=NULL;
if(head==NULL)
 head=ne;
else
{
ne->right=head;
head->left=ne;
head=ne;
}
}
}
void insert_last()
{
int x;
struct node *ne,*ptr;
ne=(struct node *)malloc(sizeof(struct node));
if(ne==NULL)
printf("Insufficient Memory");
else
{
printf("\nEnter the data to insert\n");
scanf("%d",&x);
ne->data=x;
ne->left=NULL;
ne->right=NULL;
if(head==NULL)
 head=ne;
else
{
ptr=head;
while(ptr->right!=NULL)
{
ptr=ptr->right;
}
ptr->right=ne;
ne->left=ptr;
}
}
}


void insert_pos()
{
int x,k;
struct node *ne,*ptr,*ptr1;
ne=(struct node *)malloc(sizeof(struct node));
if(ne==NULL)
printf("Insufficient Memory");
else
{
printf("\nEnter the data to insert\n");
scanf("%d",&x);
printf("\nEnter the key value\n");
scanf("%d",&k);
ne->data=x;
ne->left=NULL;
ne->right=NULL;
if(head==NULL)
 head=ne;
else
{
ptr=head;
while(ptr->right!=NULL && ptr->data!=k)
ptr=ptr->right;
if(ptr->right==NULL)
{
ptr->right=ne;
ne->left=ptr;
}
else
{
ptr1=ptr->right;
ne->right=ptr1;
ptr1->left=ne;
ptr->right=ne;
ne->left=ptr;
}
}
}
}



void delete_first()
{
struct node *ptr;
if(head==NULL)
printf("List is Empty");
else
{
ptr=head;
if(ptr->right==NULL)
{
head=NULL;
free(ptr);
}
else
{
if(head!=NULL)
{
head->left=NULL;
head=head->right;
free(ptr);
}
}
}
}

void delete_last()
{
struct node *ptr,*prev;
if(head==NULL)
printf("List is Empty");
else
{
if(head->right==NULL)
{
free(head);
head=NULL;
}
else
{
ptr=head;
while(ptr->right!=NULL)
{
ptr=ptr->right;
}
prev=ptr->left;
prev->right=NULL;
free(ptr);
}
}
}

void delete_pos()
{
struct node *ptr,*next,*prev;
int x;
if(head==NULL)
printf("\nList is empty");
else
{
printf("\nEnter the data:\n");
scanf("%d",&x);
if(head->data==x)
{
ptr=head;
head=head->right;
if(head!=NULL)
{
head->left=NULL;
}
free(ptr);
return;
}

ptr=head;
while(ptr->data!=x && ptr->right!=NULL)
ptr=ptr->right;
if(ptr->data==x)
{
next=ptr->right;
prev=ptr->left;
prev->right=ptr->right;
if(next!=NULL)
next->left=prev;
free(ptr);
return;
}
printf("\nElement not found");
}
}




void display()
{
struct node *ptr;
if(head==NULL)
printf("List is empty");
else
{
ptr=head;
printf("List:");
while(ptr!=NULL)
{
printf("%d\t",ptr->data);
ptr=ptr->right;
}
}
}



void search()
{
struct node *ptr;
int x,c=0;
if(head==NULL)
printf("List is empty");
else
{
printf("Enter the element to search\n");
scanf("%d",&x);
ptr=head;
while(ptr!=NULL)
{
if(ptr->data==x)
{
c=1;
printf("\nElement found:");
break;
}
ptr=ptr->right;
}
if(c==0)
printf("\nElement not found");
}
}



