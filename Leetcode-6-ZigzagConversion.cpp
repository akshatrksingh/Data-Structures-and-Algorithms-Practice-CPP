class Solution 
{
    public:
        string convert(string s, int numRows) 
        {
            if(numRows == 1)
            {
                return s;
            }
            int n = s.size();
            vector<string> zig(numRows);
            int dir = 1, j = 0;
            for(int i = 0; i < n; i++)
            {
                zig[j] += s[i];
                if(j == 0)
                    dir = 1;
                if(j == numRows-1)
                    dir = -1;
                j += dir;
            }
            string res = "";
            for(string x: zig)
            {
                res += x;
            }
            return res;
        }
};
