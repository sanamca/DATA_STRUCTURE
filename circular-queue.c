#include<stdio.h>
void insert(int *);
void display(int *);
void delet(int *);
void search(int *);
int front=-1,rear=-1,sz=4;
void main()
{
int q[20],opt;
do {
printf("\nMenu");
printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
printf("Select your option\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
insert(q);
break;
case 2:
delet(q);
break;
case 3:
search(q);
break;
case 4:
display(q);
break;
default:
printf("Exited");
}
}while(opt!=5);

}

void insert(int *q)
{
if(front==(rear+1)%sz)
{
printf("Queue is full\n");
return;
}
if(front==-1)
front=0;
rear=(rear+1)%sz;
printf("Enter the element to insert\n");
scanf("%d",&q[rear]);
}


void delet(int *q)
{
if(front==-1)
{
printf("Queue is empty\n");
return;
}
printf("Deleted Element %d",q[front]);
if(front==rear)
front=rear=-1;
else
front=(front+1)%sz;
printf("\n");
return;

}


void display(int *q)
{
int f;
if(front==-1)
{
printf("\nQ is empty");
return;
} 
f=front;
printf("\nElements in the queue:");
while(1)
{
printf("%d\t",q[f]);
if(f==rear)
break;
f=(f+1)%sz;
}
printf("\n");
}

void search(int *q)
{
int f,n,c=0;
printf("Enter the element to search\n");
scanf("%d",&n);
if(front==-1)
{
printf("Q is empty");
return;
} 
f=front;
while(1)
{
if(n==q[f])
{
printf("%d",q[f]);
printf("\nElement found");
break;
}
if(f==rear)
{
printf("\nElement not found");
break;
}
f=(f+1)%sz;
}
printf("\n");
}




