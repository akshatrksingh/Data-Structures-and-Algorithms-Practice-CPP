class Solution 
{
    public:
        vector<string> res;
    
        void backtrack(int open, int close, string s, int n)
        {
            if(s.size() == 2*n)
            {
                res.push_back(s);
                return;
            }
            if(open < n)
                backtrack(open+1, close, s+"(", n);
            if(close < open)
                backtrack(open, close+1, s+")", n);
        }
    
        vector<string> generateParenthesis(int n) 
        {
            backtrack(0, 0, "", n);
            return res;
        }
};
