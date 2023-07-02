class Solution 
{
    public:
        string reverseWords(string s) 
        {
            s += ' ';
            int n = s.size();
            string x = "", word = "";
            for(int i = 0; i < n-1; i++)
            {
                if(s[i] != ' ')
                {
                    word += s[i];
                }
                if (s[i] != ' ' && s[i+1] == ' ')
                {
                    x = word + ' ' + x;
                    word = "";
                }
            }
            return x.substr(0, x.size()-1);
        }
};
