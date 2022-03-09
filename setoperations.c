#include<stdio.h>
#include<string.h>
void setunion(char *,char *,char *);
void setintersection(char *,char *,char *);
void difference(char *,char *,char *);

void main()
{

int l1,l2;
char s1[20],s2[20],s3[20];

printf("Enter the set 1:");
scanf("%s",s1);

printf("Enter the set 2:");
scanf("%s",s2);

l1=strlen(s1);
l2=strlen(s2);

if(l1 == l2)
{
printf("\nFirst set= %s",s1);
printf("\nSecond set=%s",s2);

setunion(s1,s2,s3);
printf("\n\nSet union=%s",s3);

setintersection(s1,s2,s3);
printf("\nSet intersection=%s",s3);

difference(s1,s2,s3);
printf("\nSet difference=%s\n",s3);
}
else
printf("\nSet operations not possible\n");

}


void setunion(char *c1,char *c2,char *c3)
{
int l=strlen(c1),i;

for(i=0;i<l;i++)
{
if(c1[i]=='0' && c2[i]=='0')
c3[i]='0';
else
c3[i]='1';
}

c3[i]='\0';
}

void setintersection(char *c1,char *c2,char *c3)
{
int l=strlen(c1),i;

for(i=0;i<l;i++)
{
if(c1[i]=='1' && c2[i]=='1')
c3[i]='1';
else
c3[i]='0';
}

c3[i]='\0';
}

void difference(char *c1,char *c2,char *c3)
{
int l=strlen(c1),i;

for(i=0;i<l;i++)
{
if(c1[i]=='1' && c2[i]=='0')
c3[i]='1';
else
c3[i]='0';
}

c3[i]='\0';
}




