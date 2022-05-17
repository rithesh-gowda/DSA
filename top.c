#include<stdio.h>
int n,visited[10],count=0,top[10],k=-1;
int a[10][10];

int dfs(int v)
{
	int w;
	count++;
	visited[v]=count;
	for(w=0;w<n;w++)
		if(a[v][w]==1 && visited[w]==0)
			dfs(w);
	printf("%d\t",v);
	top[++k]=v;
}
void main()
{
	int v;
	printf("Enter the no.of vertex:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("------Adjacency matrix------\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	
	printf("----------DFS Traversal--------\n");
	for(int i=0;i<n;i++)
		visited[v]=0;
	for(int i=0;i<n;i++)
		if(visited[i]==0)
			dfs(i);
	printf("\n");
	printf("--------Topology Sorting---------\n");
	for(int i=n-1;i>=0;i--)
		printf("%d\t",top[i]);
	printf("\n");
}	
