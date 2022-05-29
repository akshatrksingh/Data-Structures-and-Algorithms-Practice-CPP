vector<int> Solution::nextGreater(vector<int> &A) 
{
    reverse(A.begin(), A.end());
    stack<int> st;
    vector<int> G;
    int max = INT_MIN;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] >= max)
        {
            max = A[i];
            G.push_back(-1);
        }
        while(!st.empty())
        {
            if(st.top() > A[i])
            {
                G.push_back(st.top());
                break;
            }
            st.pop();
        }
        st.push(A[i]);
    }
    reverse(G.begin(), G.end());
    return G;
}
