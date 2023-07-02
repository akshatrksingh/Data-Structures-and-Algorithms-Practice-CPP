class Solution 
{
    public:
        int strStr(string sh, string sn) 
        {
            int h = sh.size(), n = sn.size(), i, j;
            for(i = 0; i < h; i++)
            {
                int k = i;
                for(j = 0; j < n; j++)
                {
                    if(sh[k++] != sn[j])
                    {
                        break;
                    }
                }
                if(j == n)
                {
                    return i;
                }
            }
            return -1;
        }
};
