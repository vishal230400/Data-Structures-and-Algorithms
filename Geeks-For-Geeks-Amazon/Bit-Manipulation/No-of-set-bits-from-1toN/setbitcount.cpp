#include<iostream>
#include<math.h>
using namespace std;

void setBitsCount(int n)
{
	int i=n+1;
	int j=1;
	i/=2;
	int count=0;
	while(j<=n+1)
	{
		count+=i*j;
		count+=((n+1)%j);
		i/=2;
		j*=2;
	}

	cout<<"No of set bits from 1 to "<<n<<" equal to "<<count;
}


int main()
{
	int n;
	cout<<"Enter no for which no of set bits from 1 to n needed to be found"<<endl;
	cin>>n;
	setBitsCount(n);
	return 0;
}