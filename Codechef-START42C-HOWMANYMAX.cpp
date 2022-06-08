#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    int a[n];
    string str;
    int s[n-1];
    int i = 0, c = 0;
    cin>>str;
    for(auto c: str)
    {
      s[i++] = c-'0';
    }
    for(i = 0; i < n-2; i++)
    {
      if(s[i] == 0 && s[i+1] == 1) 
        c++;
    }
    if(s[0] == 1) c++;
    if(s[n-2] == 0) c++;
    if(n == 2) cout<<1<<"\n";
    else cout<<c<<"\n";
  }  
  return 0;
}