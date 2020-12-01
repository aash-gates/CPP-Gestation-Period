#include<stdio.h>
#include<math.h>
#include<string.h>
int top=-1, i;
char postfix[20], symbol;
double Compute(char symbol, double op1, double op2)
{
switch(symbol)
{
case '+': return op1 + op2;
case '-': return op1 - op2;
case '*': return op1 * op2;
case '/': return op1 / op2;
case '%': return (double)((int)(op1) % (int)(op2));
case '^': return pow(op1,op2);
default: return 0;
}
}
void push(float stack[], int item)
{
if (top == (MAX-1))
printf("\n\nStack is Overflow");
else
{
top++;
stack[top] = item;
}
}
int pop(float stack[])
{
int ret;
if(top == -1)
printf("\n\nStack is Underflow");
else
{
ret = stack[top--];
printf("\nPopped element is %d", ret);
}
return ret;
}
void evaluation()
{
float r,s[20],op1,op2,result;
clrscr();
for(i=0; i<strlen(postfix); i++)
{
symbol = postfix[i];
if(isdigit(symbol))
push(s,(symbol - '0'));
else
{
op2 = pop(s);
op1 = pop(s);
r=Compute(symbol, op1, op2);
push(s,r);
}
}
result=pop(s);
printf("\nThe result is : %f\n", result);
}
void main()
{
int n,ch;
clrscr();
printf("\nEnter the postfix expression:");
scanf("%s",postfix);
evaluation();
getch();
}