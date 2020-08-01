#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;  
    *a = *b;  
    *b = temp;  
}

int partition(int array[],int l,int h)
{
	int pivot=array[h];
	int i=l;
	for(int j=0;j<h;j++)
	{
		if(array[j]<pivot)
		{
			swap(&array[i],&array[j]);
			i++;
		}
	}

	swap(&array[i],&array[h]);
	return i;
}

void quickSort(int array[],int l,int h)
{
	if(l<h)
	{
		int p=partition(array,l,h);
		quickSort(array,l,p-1);
		quickSort(array,p+1,h);
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
	quickSort(array,0,n-1);
	cout<<"Sorted array"<<endl;
	printArray(array,n);
	return 0;				
 } 
