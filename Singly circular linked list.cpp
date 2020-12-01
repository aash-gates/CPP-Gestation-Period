#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
struct node
{
int coef, powx, powy, powz;
int flag;
struct node *link;
};
typedef struct node NODE;
NODE* getnode()
{
NODE *x;
x=(NODE*)malloc(sizeof(NODE));
if(x==NULL)
{
printf("Insufficient memory\n");
exit(0);
}
return x;
}
void display(NODE *head)
{
NODE *temp;
if(head->link==head)
{
printf("Polynomial does not exist\n");
return;
}
temp=head->link;
printf("\n");
while(temp!=head)
{
printf("%d x^%d y^%d z^%d",temp->coef,temp->powx,temp->powy,temp->powz);
if(temp->link != head)
printf(" + ");
temp=temp->link;
}
printf("\n");
}
NODE* insert(int coef,int x,int y,int z,NODE *head)
{
NODE *temp,*cur;
temp=getnode();
temp->coef=coef;
temp->powx=x;
temp->powy=y;
temp->powz=z;
cur=head->link;
while(cur->link!=head)
{
cur=cur->link;
}
cur->link=temp;
temp->link=head;
return head;
}
NODE* read_poly(NODE *head)
{
int powx, powy, powz, coef, ch;
printf("\nEnter coeff: ");
scanf("%d",&coef);
printf("\nEnter x, y, z powers(0-indiacate NO term): ");
scanf("%d%d%d", &powx, &powy, &powz);
head=insert(coef,powx,powy,powz,head);
printf("\nIf you wish to continue press 1 otherwise 0: ");
scanf("%d", &ch);
while(ch != 0)
{
printf("\nEnter coeff: ");
scanf("%d",&coef);
printf("\nEnter x, y, z powers(0-indiacate NO term): ");
scanf("%d%d%d", &powx, &powy, &powz);
head=insert(coef,powx,powy,powz,head);
printf("\nIf you wish to continue press 1 otherwise 0: ");
scanf("%d", &ch);
}
return head;
}
NODE* add_poly(NODE *h1,NODE *h2,NODE *h3)
{
NODE *p1,*p2;
int x1,x2,y1,y2,z1,z2,coef1,coef2,coef;
p1=h1->link;
while(p1!=h1)
{
x1=p1->powx;
y1=p1->powy;
z1=p1->powz;
coef1=p1->coef;
p2=h2->link;
while(p2!=h2)
{
x2=p2->powx;
y2=p2->powy;
z2=p2->powz;
coef2=p2->coef;
if(x1==x2 && y1==y2 && z1==z2)
break;
p2=p2->link;
}
if(p2!=h2)
{
coef=coef1+coef2;
p2->flag=1;
if(coef!=0)
h3=insert(coef,x1,y1,z1,h3);
}
else
h3=insert(coef1,x1,y1,z1,h3);
p1=p1->link;
}
p2=h2->link;
while(p2!=h2)
{
if(p2->flag==0)
h3=insert(p2->coef,p2->powx,p2->powy,p2->powz,h3);
p2=p2->link;
}
return h3;
}
void evaluate(NODE *h1)
{
NODE *head;
int x, y, z;
float result=0.0;
head=h1;
printf("\nEnter x, y, z, terms to evaluate:\n");
scanf("%d%d%d", &x, &y, &z);
while(h1->link != head)
{
result = result + (h1->coef * pow(x,h1->powx) * pow(y,
h1->powy) *pow(z,h1->powz));
h1=h1->link;
}
result = result + (h1->coef * pow(x,h1->powx) * pow(y,h1->powy) *pow(z,h1->powz));
printf("\nPolynomial result is: %f", result);
}
void main()
{
NODE *h1,*h2,*h3;
int ch;
clrscr();
h1=getnode();
h2=getnode();
h3=getnode();
h1->link=h1;
h2->link=h2;
h3->link=h3;
while(1)
{
printf("\n\n1.Evaluate polynomial\n2.Add two polynomials\n3.Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1:
h1->link=h1;
printf("\nEnter polynomial to evaluate:\n");
h1=read_poly(h1);
display(h1);
evaluate(h1);
break;
case 2:
h1->link=h1;
h2->link=h2;
h3->link=h3;
printf("\nEnter the first polynomial:");
h1=read_poly(h1);
printf("\nEnter the second polynomial:");
h2=read_poly(h2);
h3=add_poly(h1,h2,h3);
printf("\nFirst polynomial is: ");
display(h1);
printf("\nSecond polynomial is: ");
display(h2);
printf("\nThe sum of 2 polynomials is: ");
display(h3);
break;
case 3:
exit(0);
break;
default:
printf("\nInvalid entry");
break;
}
}
}