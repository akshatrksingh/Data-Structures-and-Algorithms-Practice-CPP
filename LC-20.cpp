class Solution 
{
    public:
    bool isValid(string s) 
    {
        stack<char> st; 
        int cnt = 0;
        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
                cnt++;
            }
            else if( st.size() >= 1 && ((st.top() == '(' && c == ')') || (st.top() == '{' && c == '}') || (st.top() == '[' && c == ']')))
                st.pop();
            else
                return false;
        }
        if(cnt*2 == s.length())
            return true;
        else
            return false;
    }
};
