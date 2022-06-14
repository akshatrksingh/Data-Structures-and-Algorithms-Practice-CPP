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
    int unique = 0, cnt = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      m[a[i]]++;
    }
    vector<int> b;
    for(auto x: m)
    {
      b.push_back(x.second);
    }
    sort(b.begin(), b.end(), greater<int>());
    if(n == 1)
    {
      cout<<1<<"\n";
    }
    else if(b.size() == 1)
    {
      cout<<n%2<<"\n";
    }
    else if(b[0] == 1)
    {
      cout<<n<<"\n";
    }
    else 
    {
      while(b[0] > 1 && b[1] > 1)
      {
        b[0]--;
        b[1]--;
        sort(b.begin(), b.end(), greater<int>());
      }
      for(int x: b)
      {
        if(x == 1)
        {
          cnt++;
        }
      }
      if(b[0] != 1) cnt += b[0]%2;
      cout<<cnt<<"\n";
    }
  }
  return 0;
}
