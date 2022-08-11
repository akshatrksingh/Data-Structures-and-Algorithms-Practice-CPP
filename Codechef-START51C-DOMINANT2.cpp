#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
    	int arr[n];
    	unordered_map<int, int> freq;
    	int mx = 0;
    	for(int i = 0; i < n; i++)
    	{
    	    cin>>arr[i];
    	    freq[arr[i]]++;
    	    if(freq[arr[i]] > mx)
    	    {
    	        mx = freq[arr[i]];
    	    }
    	}
    	int cnt = 0;
    	for(int i = 0; i < n; i++)
    	{
    	    if(freq[arr[i]] == mx)
    	    {
    	        cnt++;
    	    }
    	}
    	if(cnt == mx)
    	{
    	    cout<<"Yes\n";
    	}
    	else
    	{
    	    cout<<"No\n";
    	}
	}
	return 0;
}
