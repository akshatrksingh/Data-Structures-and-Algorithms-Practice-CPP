class Solution
{
public:
    vector<int> Reverse(stack<int> s)
    {
        vector<int> rev;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            rev.push_back(s.top());
            s.pop();
        }
        return rev;
    }
};
