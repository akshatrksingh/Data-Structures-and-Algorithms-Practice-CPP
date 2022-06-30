#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, k;
  cin>>t;
  while(t--)
  {
    cin>>n;
    cin>>k;
    cout<<ceil(n/5)-ceil(k/5)<<"\n";
  }  
  return 0;
}
