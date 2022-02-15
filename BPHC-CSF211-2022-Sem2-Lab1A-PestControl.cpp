#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> v;

void pest_control(int k, string s)
{
	int n = s.size();
	if(k == 1)
	{
		v.push_back(s);
		return;
	}
	else if(*(s.end()-1) == 'R')
	{
		pest_control(k-1, s+"R");
		pest_control(k-1, s+"S");
	}
	else if(*(s.end()-1) == 'S')
	{
		pest_control(k-1, s+"R");
	}
}

int main()
{
	int k;
	cin>>k;
	pest_control(k, "R");
	pest_control(k, "S");
	cout<<v.size()<<endl;
	for(auto s: v)
	{
		cout<<s<<endl;
	}
	return 0;
}