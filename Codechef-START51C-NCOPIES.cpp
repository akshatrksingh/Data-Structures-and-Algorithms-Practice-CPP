#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, m;
        string s;
        cin>>n>>m;
        cin>>s;
        
        long long sum = 0;
        for(long long i = 0; i < n; i++)
	    {
	        sum += s[i]-'0';
	    }
        if(sum == 0)
        {
            cout<<n*m<<"\n";
        }
        else if(sum*m%2 == 1)
        {
            cout <<0<<"\n";
        }
        else
        {
            if(m%2 == 0)
            {
                s += s, 
                sum += sum;
            }
            long long prefSum = 0, count = 0;
            for(long long i = 0; i < s.size(); i++)
            {
                prefSum += s[i]-'0';
                if(2*prefSum == sum)
                {
                    count++;
                }
            }
            cout<<count<<"\n";
        }
    }
    return 0;
}
