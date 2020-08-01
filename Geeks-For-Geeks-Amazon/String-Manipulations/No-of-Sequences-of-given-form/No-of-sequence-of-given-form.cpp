#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

void count(string s)
{
	int a=0;
	int b=0;
	int c=0;

	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a')
			a=1+2*a;
		else if(s[i]=='b')
			b=a+2*b;
		else if(s[i]=='c')
			c=b+2*c;
	}

	cout<<"Count of sequences of the given form is "<<c<<endl;
}

int main()
{
	string s;
	cout<<"Enter the string containing a b c"<<endl;
	cin>>s;
	count(s);
	return 0;
}