// Program to find adjacency matrix of directed/undirected graphs.

#include<iostream>
#define MAX 100

int adj[MAX][MAX];
int n;
using namespace std;

main()
{
	int max_edges, i,j,origin,destin;
	int graph_type;
	cout<<"\nEnter 1 for undirected graph and 2 for directed : ";
	cin>>graph_type;
	cout<<"\nEnter number of vertices : ";
	cin>>n;
	if(graph_type == 1)
		max_edges = n*(n-1)/2;
	else
		max_edges = n*(n-1);
	cout<<"\nEnter edges from 0 to n-1. V0,V1,V2......Vn-1 ";
	for(i=1; i<=max_edges; i++)
	{
		cout<<"\nEnter edge "<<i<<"(-1 -1  to quit) : ";
		cin>>origin>>destin;
		if((origin == -1) && (destin == -1))
			break;
		if(origin >= n || destin >= n || origin<0 || destin<0)
		{
			cout<<"\nInvalid vertex";
			i--;
		}	
		else
		{
			adj[origin][destin] = 1;
			if(graph_type == 1)
				adj[destin][origin] = 1;
		}
	}
	cout<<"\nThe adjacency matrix is : \n";		// Matrix for undirected graphs will be symmetric.
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<adj[i][j];
		cout<<"\n";
	}
}
		
		

