class Solution 
{
    public:
        string reorderSpaces(string text) 
        {
            int space = 0, word = 0, n = text.size();
            string t;
            vector<string> x;
            for(int i = 0; i < n; i++)
            {
                if(text[i] == ' ')
                {
                    space++;
                }
                if(i >= 1 && text[i-1] != ' ' && text[i] == ' ')
                {
                    x.push_back(t);
                    word++;
                    t = "";
                }
                else if(i < n-1 && text[i] != ' ')
                {
                    t += text[i];
                }
                else if(i == n-1 && text[i] != ' ')
                {
                    word++;
                    t += text[i];
                    x.push_back(t);
                }
            }
            
            if(space == 0)
            {
                return text;
            }
            if(word == 1)
            {
                for(int i = 1; i <= space; i++)
                {
                    x[0] += ' ';
                }
                return x[0];
            }
            
            string s, b1 = "", b2 = "";
            for(int i = 1; i <= space/(word-1); i++)
            {
                b1 += " ";
            }
            for(int i = 1; i <= space%(word-1); i++)
            {
                b2 += " ";
            }
            
            for(int i = 0; i < x.size(); i++)
            {
                s += x[i];
                if(i != x.size()-1)
                   s += b1;
            }
            s += b2;
            return s;
        }
};
