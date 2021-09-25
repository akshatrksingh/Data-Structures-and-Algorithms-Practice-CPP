vector<vector<int>> Solution::threeSum(vector<int> &S) 
{
    if(S.empty())
    {
        return {};
    }
    vector<vector<int>> v;
    sort(S.begin(), S.end());
    long long sum;
    bool flag;
    for(auto it1 = S.begin(); it1 < S.end()-2; it1++)
    {
        auto it2 = it1+1;
        auto it3 = S.end()-1;
        while(it2 != S.end() && it3 != it1 && it3 != it2)
        {
            flag = true;
            sum = (long long)*it1 + (long long)*it2 + (long long)*it3;
            if(sum == 0)
            { 
                for(auto x: v)
                {
                    if((x[0] == *it1 && x[1] == *it2) || (x[0] == *it1 && x[2] == *it2) || (x[1] == *it1 && x[0] == *it2) || (x[1] == *it1 && x[2] == *it2) || (x[2] == *it1 && x[0] == *it2) || (x[2] == *it1 && x[1] == *it2))                
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    v.push_back({*it1, *it2, *it3});
                }
                it2++;
                it3--;
            }  
            else if(sum < 0)
            {
                it2++;
            }
            else
            {
                it3--;
            }
        }
    }
    return v;
}
