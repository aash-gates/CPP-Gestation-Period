
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
/* Global variables declaration */
int a[MAX], n=0, elem, i, pos;
/*Function Prototype and Definitions*/
void create() //creating an array
{
printf("\nEnter the size of the array elements: ");
scanf("%d", &n);
printf("\nEnter the elements for the array:\n");
for(i=0; i<n; i++)
scanf("%d", &a[i]);
}
void display() //displaying an array elements
{
int i;
if(n==0)
{
printf("\nNo elements to delete\n");
}
else 
{
printf("\nThe array elements are:\n");
for(i=0; i<n; i++)
{
printf("%d\t", a[i]);
}
}
}
void insert() //inserting an element in to an array
{
printf("\nEnter the position for the new element: ");
scanf("%d", &pos);
printf("\nEnter the element to be inserted: ");
scanf("%d", &elem);
for(i=n-1; i>=pos; i--)
{
a[i+1] = a[i];
}
a[pos] = elem;
n = n+1;
}
void delete() //deleting an array element
{
if(n==0)
{
printf("\nNo elements to delete\n");
}
else
{
printf("\nEnter the position of the element to be deleted: ");
scanf("%d", &pos);
elem = a[pos];
for(i=pos; i<n-1; i++)
{
a[i] = a[i+1];
}
n = n-1;
printf("\nThe deleted element is = %d", elem);
}
}
void main()
{
int ch;
do{
printf("\n\n--------Menu-----------\n");
printf(" 1.Create\n 2.Display\n 3.Insert\n 4.Delete\n 5.Exit\n");
printf("-------------------------------");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: create();
break;
case 2: display();
break;
case 3: insert();
break;
case 4: delete();
break;
case 5: exit(0);
break;
default: printf("\nInvalid choice:\n");
break;
}
}while(5);
} // end of main