class Solution 
{
    public:
        int calculate(string s) 
        {
            int res = 0, num = 0, sign = 1;
            stack<int> st;
            st.push(1);
            for(char ch: s)
            {
                if(isdigit(ch)) 
                {
                    num = num * 10 + (ch - '0');
                }
                else
                {
                    res += num * sign * st.top();
                    num = 0;
                    if(ch == '-') 
                    {
                        sign = -1;
                    }
                    else if(ch == '+') 
                    {
                        sign = 1;
                    }
                    else if(ch == '(') 
                    {
                        st.push(st.top() * sign);
                        sign = 1;
                    }
                    else if(ch == ')') 
                    {
                        st.pop();
                    }
                }
            }
            return res += (num * sign);
        }
};
