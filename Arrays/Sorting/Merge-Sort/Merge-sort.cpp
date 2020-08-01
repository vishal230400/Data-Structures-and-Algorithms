#include<iostream>
using namespace std;

void printArray(int array[],int n)
{
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

void merge(int array[],int l,int m,int r)
{
	int l_size=m+1-l;
	int r_size=r-m;	
	int left[l_size];
	int right[r_size];
	int n=(l_size>r_size)?l_size:r_size;
	for(int i=0;i<n;i++)
	{
		if(i<l_size)
			left[i]=array[l+i];
		if(i<r_size)
			right[i]=array[m+1+i];
	}

	int k=l;
	int j=0,i=0;

	while(i<l_size && j<r_size)
	{
		if(left[i]<=right[j])
		{	
			array[k]=left[i];
			k++;
			i++;	
		}
		else
		{
			array[k]=right[j];
			k++;
			j++;	
		}
	}

	while(i<l_size)
	{
			array[k]=left[i];
			k++;
			i++;	
	}

	while(j<r_size)
	{
			array[k]=right[j];
			k++;
			j++;	
	}
}

void mergeSort(int array[],int l,int r)
{
	int mid=l+(r-l)/2;
	if(l<r)
	{
		mergeSort(array,l,mid);
		mergeSort(array,mid+1,r);
		merge(array,l,mid,r);
	}
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
	mergeSort(array,0,n-1);
	cout<<"Sorted array"<<endl;
	printArray(array,n);
	return 0;				
 } 