#include<stdio.h>
int d[10],p[10],cost[10][10],n;


void dijik(int src)
{
	int s[10],v,u,min;
	for(int i=0;i<n;i++)
	{
		d[i]=cost[src][i];
		p[i]=src;
		s[i]=0;
	}
	s[src]=1;
	for(int i=0;i<n;i++)
	{
		min=99;
		u=-1;
		for(int j=0;j<n;j++)
		{
			if(s[j]==0)
			
				if(d[j]<min)
				{
					min=d[j];
					u=j;
				}
		}
			if(u==-1)
				return;
			s[u]=1;
		
		for(v=0;v<n;v++)
		{
			if(s[v]==0)
				if(d[u]+cost[u][v]<d[v])
				{
					d[v]=d[u]+cost[u][v];
					p[v]=u;
				}
		}
	}
}

void shortdistance(int src,int dist)
{
	int i=dist;

	while(src!=i)
	{
		printf("%d<--",i);
		i=p[i];
	}
	printf("%d=%d",i,d[dist]);
	printf("\n");
}

void main()
{
	int src,i,j;
	printf("Enter the number of vertex:");
	scanf("%d",&n);
	printf("Enter the value for cost adjacency matrix");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",cost[i][j]);
		printf("\n");
	}
	printf("Enter the source vertex:");
	scanf("%d",&src);
	dijik(src);
	for(int i=0;i<n;i++)
		shortdistance(src,i);
}	
