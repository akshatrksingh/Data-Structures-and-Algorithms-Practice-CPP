int Solution::strStr(const string s1, const string s2) 
{
    int N = s1.size(), M = s2.size();
    string s;
    for(int i = 0; i < N-M+1; i++)
    {
        s = "";
        for(int j = 0; j < M; j++)
        {
            s += s1[i+j];
        }
        if(s == s2)
        {
            return i;
        }
    }
    return -1;
}
// TC: O(M*(N-M+1))
// In order to improve the TC to O(N+M), use the KMP Algorithm
