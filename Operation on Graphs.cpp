#include<stdlib.h>
#include<stdio.h>
int adj[20][20],visited[20], G[20], front = -1,rear =-1, top = -1,n,i;
void BFS(int v) { //uses G as Queue
int cur;
visited[v] = 1;
G[++rear] = v;
while(front!=rear)
{
cur = G[++front];
for(i=1;i<=n;i++)
{
if((adj[cur][i]==1)&&(visited[i]==0))
{
G[++rear]=i;
visited[i]=1;
printf("%d--%d \n",cur,i);
}
}
}
}
void DFS(int v)
{ //uses G as Stack
visited[v]=1;
G[++top] = v;
for(i=1;i<=n; i++)
{
if(adj[v][i] == 1 && visited[i] == 0 )
{
printf("\n%d -- %d", v, i);
DFS(i);
}
}
}
int main()
{
int ch, start, i, j;
clrscr();
printf("\nEnter the number of vertices in graph: ");
scanf("%d", &n);
printf("\nEnter the adjacency matrix:\n");
for(i=1; i<=n; i++)
for(j=1; j<=n; j++)
scanf("%d", &adj[i][j]);
do
{
printf("\n1. Reachable vertices using BFS\n2. Reachable vertices using DFS");
printf("\n3. Exit");
printf("\n Enter your choice: ");
scanf("%d", &ch);
if(ch==3)
exit(0);
for(i=1;i<=n;i++)
visited[i] = 0;
printf("\n Enter the starting vertex: ");
scanf("%d", &start);
printf("\nNodes reachable from starting vertex %d are:", start);
switch(ch)
{
case 1: BFS(start); break;
case 2: DFS(start); break;
case 3: exit(0); break;
}
}while(ch!=3);
getch();
return 1;
}