#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;  
    *a = *b;  
    *b = temp;  
}

void selectionSort(int array[],int n)
{
	int min_index;
	for(int i=0;i<n-1;i++)
		{
			min_index=i;
			for(int j=i+1;j<n;j++)
			{
				if(array[j]<array[min_index])
					min_index=j;
			}
			swap(&array[i],&array[min_index]);
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
	selectionSort(array,n);
	cout<<"Sorted array"<<endl;
	printArray(array,n);
	return 0;				
 } 
