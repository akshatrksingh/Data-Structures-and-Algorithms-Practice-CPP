#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, x;
  cin>>t;
  while(t--)
  {
    cin>>n;
    cin>>x;
    char s[n];
    char c = 'a';
    if(x > ceil(double(n)/2.0))
    {
      cout<<"-1\n";
    }
    else
    {
      for(int i = 0; i < x; i++)
      {
        s[i] = c;
        s[n-1-i] = c;
        c++;
      }
      c--;
      for(int i = x; i < ceil(double(n)/2.0); i++)
      {
        s[i] = c;
        s[n-1-i] = c;
      }
      s[n] = 0;
      cout<<s<<"\n";
    }
  }  
  return 0;
}
