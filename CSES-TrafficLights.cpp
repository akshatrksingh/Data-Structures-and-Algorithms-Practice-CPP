/*
//TLE

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int x, n;
    cin>>x>>n;

    vector<int> v(n+2);
    v.push_back(0);
    v.push_back(x);
    int a;
    for(int i = 0; i < n; i++) 
    {
        cin>>a;
        v.push_back(a);
        sort(v.begin(), v.end());
        int ans = 0;
        for(int j = 1; j < v.size(); j++)
        {
            ans = max(ans, v[j]-v[j-1]);
        }
        cout<<ans<<" ";
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int x, n;
    cin>>x>>n;
    set<int> s;
    multiset<int> m; // can store duplicates
    s.insert(0);
    s.insert(x);
    m.insert(x-0);
    int a;
    for(int i = 0; i < n; i++) 
    {
        cin>>a;
        s.insert(a);
        auto it = s.find(a);
        int p = *prev(it);
        int n = *next(it);
        m.erase(m.find(n-p));
        m.insert(a-p);
        m.insert(n-a);
        cout<<*m.rbegin()<<" ";
    }
    return 0;
}
