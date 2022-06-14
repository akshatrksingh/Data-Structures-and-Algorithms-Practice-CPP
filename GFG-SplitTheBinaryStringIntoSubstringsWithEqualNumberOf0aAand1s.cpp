class Solution 
{
    public:
        int maxSubStr(string str)
        {
            int zero = 0, one = 0, cnt = 0;
            for(char c: str)
            {
                if(c == '0') zero++;
                else one++;
                if(zero == one) 
                {
                    cnt++;
                    zero = 0;
                    one = 0;
                }
            }
            if(zero == 0 && one == 0 && cnt) return cnt;
            else return -1;
        }
};
