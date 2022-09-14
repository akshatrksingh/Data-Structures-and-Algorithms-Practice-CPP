class Solution 
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) 
        {
            stack<int> st;
            unordered_map<int, int> nge;
            for(int n: nums2)
            {
                while(!st.empty() && st.top() < n)
                {
                    nge[st.top()] = n;
                    st.pop();
                }
                st.push(n);
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
