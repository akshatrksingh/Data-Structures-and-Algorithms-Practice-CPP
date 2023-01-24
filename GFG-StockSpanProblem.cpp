class Solution
{
    public:
    
        vector<int> nearestGreaterLeft(int nums[], int n) 
        {
            vector<int> res(n, -1);
            stack<int> st;
            for (int i = n-1; i >= 0; i--) 
            {
                while (!st.empty() && nums[st.top()] < nums[i]) 
                {
                    res[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
            return res;
        } 
    
        vector <int> calculateSpan(int price[], int n)
        {
            vector<int> ngl = nearestGreaterLeft(price, n);
            vector<int> ans(n);
            for(int i = 0; i < n; i++)
            {
                ans[i] = i-ngl[i];
            }
            return ans;
        }
};
