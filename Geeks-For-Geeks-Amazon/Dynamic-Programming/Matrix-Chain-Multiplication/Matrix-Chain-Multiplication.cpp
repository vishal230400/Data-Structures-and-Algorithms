#include<iostream>
using namespace std;


void matrixChainMultiplication(int d[],int n)
{
	int M[n][n],S[n][n];
	for(int i=1;i<n;i++)
	{
		M[i][i]=0;
	}

	for(int l=2;l<;l++)
	{
		for(int i=0;i<=n-l+1;i++)
		{
			int j=i+l-1;
			M[i][j]=INT_MAX;
			for(int k=i;k<j;k++)
			{
				int count=M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
				if(count<M[i][j])
				{
					M[i][j]=count;
					S[i][j]=k;
				}
			}
		}
	}

	cout<<"M table"<<endl;

	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			{
				cout<<M[i][j]<<" ";
			}
		cout<<endl;	
	}

	cout<<"S table"<<endl;

	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			{
				cout<<S[i][j]<<" ";
			}
		cout<<endl;	
	}
}

int main()
{
	int n;
	cout<<"Enter number orders of matrix"<<endl;
	cin>>n;
	int d[n];
	cout<<"Enter the orders"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	matrixChainMultiplication(d,n);
	return 0;
}
