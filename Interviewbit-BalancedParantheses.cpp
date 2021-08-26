int Solution::solve(string str) 
{
    stack<char> st;
    stack<char> st1;
    stack<char> st2;

    for(auto c: str)
    {
        if(c == '(')
        {
            st.push(c);
            st1.push(c);
        }
        else
        {
            st2.push(c);
            if(st.empty())
            {
                return 0;
            }
            st.pop();
        }
    }
    return st1.size()==st2.size();
}
