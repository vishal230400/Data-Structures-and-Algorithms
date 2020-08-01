#include<iostream>
using namespace std;

void count(int a[],int n)
{
	int max,temp;
	max=a[n-1];
	a[n-1]=-1;
	for(int i=n-2;i>=0;i--)
	{
		temp=a[i];
		a[i]=max;
		if(temp>max)
			max=temp;
	}

	cout<<"Modified array "<<endl;
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	cout<<"Enter the no of elements in a array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the elements of the array"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	count(a,n);
	return 0;
}