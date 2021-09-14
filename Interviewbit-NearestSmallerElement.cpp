vector<int> Solution::prevSmaller(vector<int> &A) 
{
    stack<int> st;
    vector<int> G;
    int min = INT_MAX;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] <= min)
        {
            min = A[i];
            G.push_back(-1);
        }
        while(!st.empty())
        {
            if(st.top() < A[i])
            {
                G.push_back(st.top());
                break;
            }
            st.pop();
        }
        st.push(A[i]);
    }
    return G;
}
