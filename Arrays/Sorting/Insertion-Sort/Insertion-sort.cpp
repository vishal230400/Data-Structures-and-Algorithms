#include<iostream>
using namespace std;

void insertionSort(int array[],int n)
{
	int j,temp;
	for(int i=1;i<n;i++)
	{	
		temp=array[i];
		j=i;
		while(array[j-1]>temp && j>=1)
		{
			array[j]=array[j-1];
			j--;
		}
		array[j]=temp;
	}
}

void printArray(int array[],int n)
{
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

int main()
{
	int array[20];
	int n;
	cout<<"Enter number of elements in the array"<<endl;
	cin>>n;
	cout<<"Enter the elemets in the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	cout<<"Unsorted array"<<endl;
	printArray(array,n);
	insertionSort(array,n);
	cout<<"Sorted array"<<endl;
	printArray(array,n);
	return 0;				
 } 
