#include<iostream>
using namespace std;

void count(int m, int n)
{
	int paths[m][n];
	for(int i=0;i<n;i++)
	{
		paths[0][i]=1;
	}
	for(int i=0;i<m;i++)
	{
		paths[i][0]=1;
	}

	for(int i=1;i<m;i++)
		for(int j=1;j<n;j++)
		{
			paths[i][j]=paths[i-1][j]+paths[i][j-1];
		}

	cout<<"No of paths in m n from top left to bottom right = "<<paths[m-1][n-1]<<endl;	
}

int main()
{
	int m,n;
	cout<<"Enter m and n respectiveky"<<endl;
	cin>>m>>n;
	count(m,n);
	return 0;
}