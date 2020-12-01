#include<stdio.h>
#include<stdlib.h>
char STR[100], PAT[50], REP[50], RES [100];
int Pattern_Match_Repace()
{ // String Matching function
int i=0; //idex for PAT
int c=0, m=0; //idex for STR
int k=0 ; //idex for REP
int flag=0;
int j=0; //index for ANS
while(STR[c] != '\0')
{
if(STR[m] == PAT[i])
{ //if same , scan the next character
m++;
i++;
if(PAT[i] == '\0')
{
// if a match is found then copy REP to RES, set flag to 1
flag = 1;
k=0;
while(REP[k] != '\0')
{
RES [j++] = REP[k++];
}
i = 0;
c = m;
}
}
else
{
RES [j++] = STR[c++]; //otherwise copy STR to RES
i = 0;
m = c;
}
}
RES [j] = '\0';
return flag;
}
int main()
{ //Main program
clrscr();
printf("\nEnter a main string :");
gets(STR);
printf("\nEnter a pattern string :");
gets(PAT);
printf("\nEnter a string to be replaced:");
gets(REP);
if(Pattern_Match_Repace())
printf("\nThe resultant string is: %s \n" , RES);
else
printf("\nPattern string NOT found\n");
getch();
return 0;
}