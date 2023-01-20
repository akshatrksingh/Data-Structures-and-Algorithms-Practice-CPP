class Solution 
{
    public String longestCommonPrefix(String[] str) 
    {
        if(str.length == 0)
        {
            return "";
        }    
        String pre = str[0];
        for(int i = 1; i < str.length; i++)
            {
                String s = str[i], tmp;
                if(pre.length() > s.length())
                {
                    tmp = s;
                    s = pre;
                    pre = tmp;
                }
                for(int j = 0; j < pre.length(); j++)
                {
                    if(pre.charAt(j) != s.charAt(j))
                    {
                        pre = s.substring(0, j);
                        break;
                    }
                }
            }
            return pre;
    }
}
