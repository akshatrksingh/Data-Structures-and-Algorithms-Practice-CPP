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
    int pos = 0, neg = 0;
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      if(a[i] == 1) pos++;
      else neg++;
    }
    if(n%2 == 1) cout<<-1<<"\n";
    else cout<<abs(pos-neg)/2<<"\n";
  }  
  return 0;
}