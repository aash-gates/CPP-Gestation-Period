#include <stdlib.h>
#define MAX 10
struct employee{
int id;
char name[15];
};
typedef struct employee EMP;
EMP emp[MAX];
int a[MAX];
void Linear_prob(int key, int num)
{
int flag=0, i=key;
if(a[i] == -1)
flag=1;
else{
printf("\nCollision Detected...!!!\n");
i=key+1;
do{
if(a[i] == -1) {
flag = 1;
break;
}
else
i=(++i)%MAX;
}while(i!=key && flag==0);
}
if(flag==0)
printf("\n Hash table is full");
else{
printf("\nEnter emp id: ");
scanf("%d",&emp[i].id);
printf("\nEnter emp name: ");
scanf("%s",emp[i].name);
a[i]=i;
printf("\nCollision avoided successfully using LINEAR PROBING\n");
}
}
void Display()
{
int i, ch;
printf("\n1.Display ALL\n2.Filtered Display \n Enter the choice:");
scanf("%d",&ch);
printf("\nHTKey\tEmpID\tEmpName");
for(i=0; i<MAX; i++){
if(ch==2 && a[i] == -1)
continue;
else
printf("\n%d\t%d\t%s", i, emp[i].id, emp[i].name);
}
}
int main()
{
int num, key, i;
int ch = 1;
clrscr();
printf("\nCollision handling by linear probing: ");
for (i=0; i < MAX; i++) {
a[i] = -1;
}
do{
printf("\nEnter the data: ");
scanf("%d", &num);
Linear_prob(num % 100,num);
printf("\nDo you wish to continue? (1/0): ");
scanf("%d",&ch);
}while(ch);
Display();
getch();
return 1;
}