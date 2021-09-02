int Solution::strStr(const string s1, const string s2) 
{
    int n = s2.size();
    string s;
    for(auto it1 = s1.begin(); it1 < s1.end()-n+1; it1++)
    {
        s = "";
        auto it2 = it1;
        int tmp = n;
        while(tmp--)
        {
            s += *it2;
            if(s == s2)
            {
                return it1-s1.begin();
            }
            it2++;
        }
    }
    return -1;
}
