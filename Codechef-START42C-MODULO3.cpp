#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n;
  cin>>t;
  while(t--)
  {
    int a, b;
    cin>>a>>b;
    if(a%3 == 0 || b%3 == 0)
      cout<<"0\n";
    else if((a%3 == 1 && b%3 == 1) || (a%3 == 2 && b%3 == 2))
      cout<<"1\n";
    else 
      cout<<"2\n";
  }  
  return 0;
}