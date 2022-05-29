vector<int> prevSmallerIndex(vector<int> &A) 
{
    stack<int> st, st1;
    vector<int> G, P;
    int min = INT_MAX;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] <= min)
        {
            min = A[i];
            G.push_back(-1);
            P.push_back(-1);
        }
        while(!st.empty())
        {
            if(st.top() < A[i])
            {
                G.push_back(st.top());
                P.push_back(st1.top());
                break;
            }
            st.pop();
            st1.pop();
        }
        st.push(A[i]);
        st1.push(i);
    }
    return P;
}

vector<int> nextSmallerIndex(vector<int> &A) 
{
    reverse(A.begin(), A.end());
    stack<int> st, st1;
    vector<int> G, N;
    int min = INT_MAX;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] <= min)
        {
            min = A[i];
            G.push_back(-1);
            N.push_back(A.size());
        }
        while(!st.empty())
        {
            if(st.top() < A[i])
            {
                G.push_back(st.top());
                N.push_back(st1.top());
                break;
            }
            st.pop();
            st1.pop();
        }
        st.push(A[i]);
        st1.push(A.size()-i-1);
    }
    reverse(A.begin(), A.end());
    reverse(N.begin(), N.end());
    return N;
}


int Solution::largestRectangleArea(vector<int> &A) 
{
    vector<int> v1 = prevSmallerIndex(A);
    vector<int> v2 = nextSmallerIndex(A);
    int max_area = 0;
    for(int i = 0; i < A.size(); i++)
    {
        max_area = max(max_area, A[i]*(v2[i]-v1[i]-1));
    }
    return max_area;  
}
