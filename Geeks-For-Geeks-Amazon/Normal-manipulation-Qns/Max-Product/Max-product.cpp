#include <iostream>
using namespace std;

void maxProduct(int array[],int n)
{
	 if (n < 2) 
    { 
        cout << "No pairs exists\n"; 
        return; 
    } 
  
    if (n == 2) 
    { 
        cout << array[0] << " " << array[1] << endl; 
        return; 
    } 
  
    int posa = INT_MIN, posb = INT_MIN; 
  
    int nega = INT_MIN, negb = INT_MIN; 
  
    for (int i = 0; i < n; i++) 
    { 
        if (array[i] > posa) 
        { 
            posb = posa; 
            posa = array[i]; 
        } 
        else if (array[i] > posb) 
            posb = array[i]; 
  
        if (array[i] < 0 && abs(array[i]) > abs(nega)) 
        { 
            negb = nega; 
            nega = array[i]; 
        } 
        else if(array[i] < 0 && abs(array[i]) > abs(negb)) 
            negb = array[i]; 
    } 
  
    if (nega*negb > posa*posb) 
        cout << "Max product pair is " << nega << ", "
             << negb; 
    else
        cout << "Max product pair is " << posa << ", "
             << posb; 
}

int main()
{
	int n;
	cout<<"Enter no of elements in the array "<<endl;
	cin>>n;
	int array[n];
	cout<<"The elements in the array"<<endl;
	for(int i=0;i<n;i++)
		cin>>array[i];
	maxProduct(array,n);
	return 0;
}