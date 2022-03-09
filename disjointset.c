
#include<stdlib.h>
#include<stdio.h>
struct node {
int data;
struct node *next;
};
void makeset();
void unionset();
int find(int);
void display();
int n=0;
struct node *first[20];

void main()
{
int opt,x,i;

do {
printf("\nMenu");
printf("\n1.makeset\n2.union\n3.find\n4.display\n5.exit");
printf("\nselect your option");
scanf("%d",&opt);
switch(opt)
{
case 1:
makeset();
break;
case 2:
unionset();
break;
case 3:
printf("Enter the value for x:");
scanf("%d",&x);
i=find(x);
if(i==-1)
printf("Element not found");
else
printf("Element=%d",first[i]->data);
break;
case 4:
display();
break;
}

}while(opt!=5);
}


void makeset()
{
int x,pos;
printf("\nEnter the element:");
scanf("%d",&x);
pos=find(x);

if (pos==-1)
{
first[n]=(struct node *)malloc(sizeof(struct node *));
first[n]->data=x;
first[n]->next=NULL;
n++;
}
else
printf("Element already exist");
}



int find(int x)
{
int i,flag=0;
struct node *p;
for(i=0;i<n;i++)
{
p=first[i];
while(p!=NULL)
{
if(p->data==x)
{
flag=1;
break;
}
p=p->next;
}
if (flag==1)
break;
}
if(flag==1)
return i;
else
return -1;
}


void unionset()
{
int a,b,i,j;
struct node *p;
printf("\nEnter the first element:");
scanf("%d",&a);
printf("\nEnter the second element:");
scanf("%d",&b);
i=find(a);
j=find(b);
if (i==-1 || j ==-1)
{
printf("element not found");
return;
}
if (i==j)
printf("Both are in the same set");
else
{
p=first[i];
while(p->next!=NULL)
p=p->next;
p->next=first[j];
first[j]=NULL;
}
}



void display()
{
int i;
struct node *p;
for(i=0;i<n;i++)
{
p=first[i];
if(p==NULL) 
continue;
printf("{");
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
printf("}\n");
}
}
