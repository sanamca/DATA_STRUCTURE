#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void search();
void display();
struct node
{
int data;
struct node *next;
};
struct node *top=NULL;
void main()
{
int opt;
do 
{
 printf("\nMenu");
 printf("\n1.push\n2.pop\n3.search\n4.display\n5.Exit");
 printf("\nSelect your option:");
 scanf("%d",&opt);
 switch(opt)
 {
 case 1:
 push();
 break;
 case 2:
 	pop();
 break;
 case 3:
search();
 break;
 case 4:
 display();
 break;
 default:
 printf("Exited");
 break;
 }
}while(opt!=5);
}


void push()
{
int x;
struct node *ne;
printf("Enter the Element to push:");
scanf("%d",&x);
ne=(struct node *)malloc(sizeof(struct node));
if(ne==NULL)
{
printf("Stack Overflow");
return;
}
ne->data=x;
ne->next=top;
top=ne;
}

void pop()
{
int item;
struct node *ptr;
if(top==NULL)
printf("\nStack is empty");
else
{
item=top->data;
ptr=top;
printf("\nPoped Element=%d",item);	
top=top->next;
free(ptr);
}
}

void search()
{
int c=0,x,f=0;
struct node *ptr;
if(top==NULL)
printf("\nStack is empty");
else 
{
printf("\nEnter the element to search:");
scanf("%d",&x);
ptr=top;
while(ptr!=NULL)
{
if(ptr->data==x)
{
f=1;
printf("\nElement found at node %d",c);
break;
}
ptr=ptr->next;
c++;
}
if(f==0)
printf("\nElement not found");
}
}



void display()
{
struct node *ptr;
if(top==NULL)
printf("Stack empty");
else 
{
ptr=top;
printf("\nElements in stack:");
while(ptr!=NULL)
{
printf("%d\t",ptr->data);
ptr=ptr->next;
}
}
}




