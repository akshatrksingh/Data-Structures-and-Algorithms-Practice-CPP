#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, h1, h2, h3, x;
  cin>>t;
  while(t--)
  {
    cin>>n;
    h1 = ceil(n/3.0) + 1;
    x = n-h1-1;
    while(x >= h1)
    {
      x--;
    }
    h2 = x;
    h3 = n-h1-h2;
    cout<<h2<<" "<<h1<<" "<<h3<<" \n";
  }  
  return 0;
}