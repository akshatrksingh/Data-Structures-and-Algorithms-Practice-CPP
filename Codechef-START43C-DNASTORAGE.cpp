#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    char s[n];
    string str;
    for(int i = 0; i < n; i += 2)
    {
      cin>>s[i];
      cin>>s[i+1];
      if(s[i] == '0' && s[i+1] == '0') str += 'A';
      else if(s[i] == '0' && s[i+1] == '1') str += 'T';
      else if(s[i] == '1' && s[i+1] == '0') str += 'C';
      else if(s[i] == '1' && s[i+1] == '1') str += 'G';
    }
    cout<<str<<"\n";
  }  
  return 0;
}
