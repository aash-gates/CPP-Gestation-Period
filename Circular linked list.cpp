#include<stdio.h>
#include<stdlib.h>
#define max 4
char q[10];
int front=0,rear=-1;
void Insert()
{
if(front==(rear+1)% max && rear>-1)
printf("Queue is overflow\n");
else
{
printf("Enter element to insert:");
rear=(++rear)%max;
scanf(" %c",&q[rear]);
printf("Rear=%d, Front=%d ",rear, front);
}
}
void Delete()
{
if((front==0)&&(rear==-1))
printf("Queue is underflow\n");
else
{
printf("Deleted element is:%c\n", q[front]);
if(front==rear)
{
rear=-1;
front=0;
}
else
front=(++front)%max;
printf("Rear=%d, Front=%d ",rear, front);
}
}
void Display()
{
int i=front;
if(rear>-1)
{
if(rear!=front)
{
do
{
printf("\t%c",q[i++]);
if(i==max&& rear>=0)
i=0;
}while(i!=rear );
}
printf("\t%c",q[i]);
}
}
void main()
{
int ch;
do
{
printf("\n Circular Queue operations: \n1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: Insert(); break;
case 2: Delete(); break;
case 3: Display();break;
case 4: exit(0);
}
}while(1);
}