#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int k[n];
    for(int i = 0; i < n; i++)
    {
        cin>>k[i];
    }
    int left = 0, right = 0;
    int res = 0;
    int i = 0;
    set<int> s;
    while(right < n)
    {
        if(s.find(k[right]) == s.end())
        {
            s.insert(k[right]);
            res = max(res, right-left+1);
            right++;
        }
        else
        {
            s.erase(k[left]);
            left++;
        }
    }
    cout<<res<<"\n";
    return 0;
}