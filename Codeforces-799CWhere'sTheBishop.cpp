#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s[8];
    for(int i = 0; i < 8; i++)
    {
      cin>>s[i];
    }
    for(int r = 1; r < 7; r++)
    {
      for(int c = 1; c < 7; c++)
      {
        if(s[r-1][c-1] == '#' && s[r-1][c+1] == '#' && s[r][c] == '#' && s[r+1][c-1] == '#' && s[r+1][c+1] == '#')
          cout<<r+1<<" "<<c+1<<"\n";
      }
    }
  }  
  return 0;
}