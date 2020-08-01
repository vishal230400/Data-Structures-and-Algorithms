#include<iostream>
using namespace std;

void shellSort(int array[],int n)
{
	int temp,j;
	for(int gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;i++)
		{	
			temp=array[i];
			j=i;
			while(array[j-gap]>temp && j>=1)
			{
				array[j]=array[j-gap];
				j-=gap;
			}
			array[j]=temp;
		}
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
	shellSort(array,n);
	cout<<"Sorted array"<<endl;
	printArray(array,n);
	return 0;				
 } 
