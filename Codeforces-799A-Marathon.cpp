#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, a, b, c, d, n;
  cin>>t;
  while(t--)
  {
    n = 0;
    cin>>a>>b>>c>>d;
    if(b>a) n++;
    if(c>a) n++;
    if(d>a) n++;
    cout<<n<<"\n";
  }  
  return 0;
}