#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;  
    *a = *b;  
    *b = temp;
}

void bubbleSort(int array[],int n)
{
	int swapped=1;
	for(int i=0;i<n-1 && swapped;i++)
		{
			swapped=0;
			for(int j=0;j<n-i-1;j++)
			{
				if(array[j]>array[j+1])
				{
					swap(&array[j],&array[j+1]);
					swapped=1;
				}
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
	bubbleSort(array,n);
	cout<<"Sorted array"<<endl;
	printArray(array,n);
	return 0;				
 } 
