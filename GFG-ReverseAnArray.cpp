#include <iostream>
using namespace std;

int main() 
{
	int t, n, m, num;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    m = n;
	    int arr[n];
	    while(n--)
	    {
	        cin>>arr[n];
	    }
	    for(int i = 0; i < m; i++)
	    {
	        cout<<arr[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
