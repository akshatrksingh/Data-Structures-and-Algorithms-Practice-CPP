int Solution::solve(string s) 
{
    stack<char> st; 
    int cnt = 0, n = 0;
    for(char c : s)
    {
        if(c == '(')
        {
            st.push(c);
            cnt++;
        }
        else if(st.size() >= 1 && (st.top() == '(' && c == ')'))
        {
            st.pop();
            n += 2;
        }
    }
    return s.size()-n;
}
