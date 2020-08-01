#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

void count(string s)
{
	int count=0;

	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
			count++;
	}

	cout<<"Count number of substrings that start and end with 1 is "<<(count)*(count-1)/2<<endl;
}

int main()
{
	string s;
	cout<<"Enter the string containing in 1's and 0's format"<<endl;
	cin>>s;
	count(s);
	return 0;
}