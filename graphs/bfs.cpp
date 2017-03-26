// Program for traversing a directed graph through BFS, and finding shortest 
// distance and shortest path of any vertex from the start vertex.
#include<stdlib.h>
#include<iostream>

using namespace std;

#define MAX 	 100
#define infinity 9999
#define NIL 	 -1
#define initial  1
#define waiting  2
#define visited  3
int n;     		// number of vertices in the graph
int adj[MAX][MAX];  	// adjacecny matrix
int state[MAX];		// can be initial, waiting or visited
int distanc[MAX];
int predecessor[MAX];
void create_graph();
void BF_traversal();
void BFS(int v);
void insert_queue(int vertex);
int queue[MAX], front = -1, rear = -1;
int delete_queue();
int isEmpty();

main()
{
	int u,v,i,count,path[MAX];
	create_graph();
	BF_traversal();
	while(1)
	{
		cout<<"\nEnter destination vertex(-1 to quit) : ";
		cin>>v;
		if(v < -1 || v > n)
		{
			cout<<"\nDestination vertex does not exist.";
			continue;
		}
		if(v == -1)
			break;
		count = 0;
		if(distanc[v] == infinity)
		{
			cout<<"\nNo path from start vertex to destination vertex.";
			continue;
		}
		else
			cout<<"\nShortest distance is : "<<distanc[v];
		while(v!=NIL)
		{
			count++;
			path[count] = v;
			u = predecessor[v];
			v = u;
		}
		cout<<"\nShortest path is : ";
		for(i=count;i>1;i--)
			cout<<path[i]<<"->";
		cout<<path[i]; 
		cout<<"\n";
	}
}  // End of main function

void BF_traversal()
{
	int v;
	for(v=0;v<n;v++)
	{
		state[v] = initial;
		predecessor[v] = NIL;
		distanc[v] = infinity;
	}
	cout<<"\nEnter the starting vertex for BFS : ";
	cin>>v;
	BFS(v);
	cout<<"\n";
}
	
void BFS(int v)
{
	int i;
	insert_queue(v);
	state[v] = waiting;
	distanc[v] = 0;
	predecessor[v] = NIL;
	while(!isEmpty())
	{
		v = delete_queue();
		state[v] = visited;
		for(i=0;i<n;i++)
		{
			// check for adjacent unvisited vertices
			if(adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
				predecessor[i] = v;
				distanc[i] = distanc[v]+1;
			}
		}
	}
}  // End of BSF

int isEmpty()
{
	if(front==-1 || front>rear)
		return 1;
	else
		return 0;
}

int delete_queue()
{
	int del_item;
	if(front==-1 || front>rear)
	{
		cout<<"\nQueue Underflow";
		exit(1);
	}
	del_item = queue[front];
	front++;
	return del_item;
}

void insert_queue(int vertex)
{
	if(rear == MAX-1)
		cout<<"\nQueue overflow";
	else
	{
		if(front==-1)
			front = 0;
		rear++;
		queue[rear] = vertex;
	}
}  // End of insert queue

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

	
