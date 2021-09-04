typedef long long ll;
vector<int> Solution::repeatedNumber(const vector<int> &v) 
{
    vector<int> s;
    ll n = v.size();
    ll ex_sum = n*(n+1)/2;
    ll sum = 0;
    for(auto i: v)
    {
        sum += i;
    }
    int diff = ex_sum - sum;
    bool b[n] = {false};
    for(auto i : v)
    {
        if(b[i-1] == true)
        {
            s.push_back(i);
            break;
        }
        b[i-1] = true;
    }
    s.push_back(s[0]+diff);
    return s;
}
