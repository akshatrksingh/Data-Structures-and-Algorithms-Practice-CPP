class Solution 
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) 
        {
            int n = nums2.size();
            unordered_map <int, int> nge;
            stack<int> st;
            for (int i = 0; i < n; i++) 
            {
                while (!st.empty() && nums2[st.top()] < nums2[i]) 
                {
                    nge[nums2[st.top()]] = nums2[i];
                    st.pop();
                }
                st.push(i);
            }
            vector<int> res;
            for (int n: nums1) 
            {
                if (nge.find(n) != nge.end()) 
                {
                    res.push_back(nge[n]);
                }
                else 
                {
                    res.push_back(-1);
                }
            }   
            return res;
        }
};
