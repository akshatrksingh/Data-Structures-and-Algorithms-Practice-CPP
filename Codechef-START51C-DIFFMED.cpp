#include <iostream>
using namespace std;

int main() 
{
    int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int mx = n, mn = 1, ans;
	    bool flag = true;
	    while(n--)
	    {
	        if(flag)
	        {
	            flag = false;
	            ans = mx;
	            mx--;
	        }
	        else
	        {
	            flag = true;
	            ans = mn;
	            mn++;
	        }
	        cout<<ans<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
