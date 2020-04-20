/* BFS */ 

#include<stdio.h>
#include<stdlib.h>
int a[10][10], q[10], visited[10], n, i, j, b = 0, c = -1;

void bfs(int d) {
 for(i = 1; i <= n; i++)
 if(a[d][i] && !visited[i])
 q[++c] = i;
 if(b <= c) {
 visited[q[b]] = 1;
 bfs(q[b++]);
 }
}

void main() {
 int d;
 printf("\n Enter the total number of vertices:");
 scanf("%d", &n);
 
 for(i=1; i <= n; i++) {
 q[i] = 0;
 visited[i] = 0;
 }
 
 printf("\n Enter the graph data which should be in matrix form :\n");
 for(i=1; i<=n; i++) {
 for(j=1;j<=n;j++) {
 scanf("%d", &a[i][j]);
 }
 }
 
 printf("\n Enter the begining vertex:");
 scanf("%d", &d);
 bfs(d);
 printf("\n Total number of nodes which are reachable are :\n");
 
 for(i=1; i <= n; i++) {
 if(visited[i])
 printf("%d\t", i);
 else {
 printf("\n BFS is not possible...All nodes are not reachable");
 break;
 }
 }
}



/*DFS */
#include<stdio.h>
#include<conio.h>
int a[20][20],reach[20],n;
void dfs(int v) {
	int i;
	reach[v]=1;
	for (i=1;i<=n;i++)
	  if(a[v][i] && !reach[i]) {
		printf("\n %d->%d",v,i);
		dfs(i);
	}
}
int main() {
	int i,j,count=0;
	
	printf("\n Enter number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		reach[i]=0;
		for (j=1;j<=n;j++)
		   a[i][j]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	dfs(1);
	printf("\n");
	for (i=1;i<=n;i++) {
		if(reach[i])
		   count++;
	}
	if(count==n)
	  printf("\n Graph is connected"); else
	  printf("\n Graph is not connected");
	getch();
	return 0;
}
