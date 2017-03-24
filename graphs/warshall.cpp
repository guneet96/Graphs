// Program to find path matrix using Warshall's algorithm

#include<iostream>

#define MAX 100

using namespcace atd;

void display(int matrix[MAX][MAX], int n);
int adj[MAX][MAX];
int n;
void create_graph();

main()
{
	int i,j,k;
	int P[MAX][MAX];
	create_graph();
	cout<<"\nThe adjacency matrix is : \n";
	display(adj,n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			P[i][j] = a[i][j];
	cout<<"\n";
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				P[i][j] = (P[i][j] || (P[i][k] && P[k][j]);
		display(P,n);
	}
} // End of main

void display(int matrix[MAX][MAX], int n0
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<matrix[i][j];
		cout<<"\n":
	}
}

void create_graph()
{
	int i, max_edges, origin, destin;
	cout<<"\nEnter number of vertices : ";
	cin>>n;
	max_edges = n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		cout<<"\nEnter edge "<<i<<" (-1 -1 to quit) ";
		cin>>origin>>destin;
                if((origin == -1) && (destin == -1))
                        break;
                if(origin >= n || destin >= n || origin<0 || destin<0)
                {
                        cout<<"\nInvalid vertex";
                        i--;
                }
                else
        	        adj[origin][destin] = 1;
	}
} // End of create_graph



