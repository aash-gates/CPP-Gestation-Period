#include<stdio.h>
#include<stdlib.h>
int MAX=4, count=0;
struct student
{
char usn[10], name[30], branch[5],sem[2],phno[10];
struct student *next;
};
typedef struct student NODE;
NODE* getnode()
{
NODE *node=(NODE*)malloc(sizeof(NODE));
printf("\nEnter USN, Name, Branch, Sem, Ph.No:");
scanf("%s%s%s%s%s",node->usn, node->name, node->branch,
node->sem,node->phno);
node->next=NULL;
count++;
return node;
}
void Display(NODE *head)
{
NODE *p;
if(head != NULL)
{
p=head;
printf("\n----STUDENT DATA----\n USN\tNAME\t\tBRANCH\tSEM\tPh.NO.");
while(p!=NULL)
{
printf("\n%s\t%s\t\t%s\t%s\t%s", p->usn,p->name,p->branch,p->sem, p->phno);
p = p->next;
}
}
if(count==0)
printf("\nNo data available!!\n");
}
NODE* Insert(NODE *head, char ch)
{
NODE *newnode,*p;
if(count==MAX)
printf("\n Overflow!!");
else
{
newnode=getnode();
if(head==NULL)
head= newnode;
else if(ch=='f')
{
newnode->next=head;
head=newnode;
}
else if(ch=='r')
{
p=head;
while(p->next!=NULL)
p=p->next;
p->next=newnode;
}
printf("\n Inserted Successfully");
}
return head;
}
NODE* Delete(NODE *head, char ch)
{
NODE *p, *q;
if(head==NULL)
printf("\nEmpty(Underflow)");
else
{
if(ch=='f')
{
p=head;
head=head->next;
free(p);
count--;
}
else if(ch=='r')
{
if (head->next==NULL)
head=NULL;
else
{
p=head;
while(p->next!=NULL)
{
q=p;
p=p->next;
}
free(p);
count--;
q->next=NULL;
}
}
printf("\n Deleted Successfully .. ");
}
return head;
}
void main()
{
int ch, i, n;
NODE *head=NULL;
clrscr();
printf("\n----------Student Database---------");
printf("\nHow many student data you want to create: ");
scanf("%d", &n);
for(i=0;i<n;i++)
head=Insert(head,'f');
do
{
printf("\n 1.Display 2.Insert-Front 3.Insert- Rear 4.Delete-Front 5.Delete- Rear\n");
printf("\n6.Stack-PUSH\n 7.Stack-POP\n 8.Exit \n Enter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: Display(head); break;
case 2: head=Insert(head,'f'); break;
case 3: head=Insert(head,'r'); break;
case 4: head=Delete(head,'f');; break;
case 5: head=Delete(head,'r');; break;
case 6: head=Insert(head,'f'); break;
case 7: head=Delete(head,'f'); break;
case 8: exit(0);
}
}while(ch);
getch();
}