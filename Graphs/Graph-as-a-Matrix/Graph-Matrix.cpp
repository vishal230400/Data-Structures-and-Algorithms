#include<iostream>
#include<bits/stdc++.h> 
#include <queue> 
using namespace std;

class graph{
public:
	int v;
	int **adj;

	graph(int v)
	{

		this->v=v;
		adj=new int*[v];
		for(int i=0;i<v;i++)
		{
			adj[i]=new int [v];
			for(int j=0;j<v;j++)
				adj[i][j]=0;
		}
	}

	void printGraph()
	{
		for(int i=0;i<v;i++)
		{
			cout<<"The neighbours of "<< i<<" are "<<endl;
			for(int j=0;j<v;j++)
			{
				cout<<j<<" "<<adj[i][j]<<endl;
			}
		}
	}

	void addEdge(int v1,int v2)
	{
		adj[v1][v2]=1;
	}

	void removeEdge(int v1,int v2)
	{
		adj[v1][v2]=0;
	}
};





int main()
{
	int v;
	cout<<"Enter the no of vertices";
	cin>>v;
	graph g=graph(v);
	int operation;
	int v1,v2;
	do{
		cout<<"Operations on Graph as Matrix"<<endl<<"1.Add Edge"<<endl<<"2.Remove Edge"<<endl<<"3.Print the graph"<<endl;
		cin>>operation;
		switch(operation)
		{
			case 1:
				{
					cout<<"Enter the vertices of Edge (v1 directs to v2) to be added"<<endl;
					cin>>v1>>v2;
					g.addEdge(v1,v2);
					cout<<endl;
					break;
				}
			case 2:
				{
					cout<<"Enter the vertices of Edge (v1 directs to v2) to be removed"<<endl;
					cin>>v1>>v2;
					g.removeEdge(v1,v2);
					cout<<endl;
					break;
				}
			case 3:
				{
					g.printGraph();
					break;
				}
			deault:
			{
				cout<<"Exiting"<<endl;
			}	
		}
	}while(operation>=1 && operation<=3);
	
	return 0;
}