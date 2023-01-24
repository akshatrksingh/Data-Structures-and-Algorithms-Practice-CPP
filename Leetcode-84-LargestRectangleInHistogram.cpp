class Solution 
{
    public:

        vector<int> nearestSmallerLeft(vector<int> &nums) 
        {
            int n = nums.size();
            vector<int> res(n, -1);
            stack<int> st;
            for (int i = n-1; i >= 0; i--) 
            {
                while (!st.empty() && nums[st.top()] > nums[i]) 
                {
                    res[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
            return res;
        } 

        vector<int> nearestSmallerRight(vector<int> &nums) 
        {
            int n = nums.size();
            vector<int> res(n, n);
            stack<int> st;
            for (int i = 0; i < n; i++) 
            {
                while (!st.empty() && nums[st.top()] > nums[i]) 
                {
                    res[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
            return res;
        } 

        int largestRectangleArea(vector<int> &h) 
        {
            int n = h.size();
            vector<int> nsl = nearestSmallerLeft(h);
            vector<int> nsr = nearestSmallerRight(h);
            int mx = 0;
            for(int i = 0; i < n; i++)
            {
                mx = max(mx, h[i]*(nsr[i]-nsl[i]-1));
            }
            return mx;
        }
};
