class MinStack 
{
    public:
    stack<int> st;
    stack<int> m;
    
    void push(int val) 
    {
        st.push(val);
        if(m.empty() || val <= m.top())
        {
            m.push(val);
        }
    }
    
    void pop() 
    {
        if(m.top() == st.top())
        {
            m.pop();
        }
        st.pop();
    }
    
    int top() 
    {
        return st.top();
    }
    
    int getMin() 
    {
        return m.top();
    }
};
