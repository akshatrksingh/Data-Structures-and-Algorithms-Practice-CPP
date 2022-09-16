/*
// DP
class Solution 
{
    public:
        int trap(vector<int> &height) 
        {
            int n = height.size(), water = 0;
            vector<int> leftMax(n), rightMax(n);
            leftMax[0] = height[0];
            for(int i = 1; i < n; i++)
            {
                leftMax[i] = max(leftMax[i-1], height[i]);    
            }
            rightMax[n-1] = height[n-1];
            for(int i = n-2; i >= 0; i--)
            {
                rightMax[i] = max(rightMax[i+1], height[i]);    
            }
            for(int i = 1; i < n-1; i++)
            {
                water += min(leftMax[i], rightMax[i]) - height[i];
            }
            return water;
        }
        // TC: 0(N)
        // SC: 0(N)
};
*/

// Stacks
class Solution 
{
    public:
        int trap(vector<int> &height) 
        {
            int water = 0, current = 0;
            stack<int> st;
            while (current < height.size()) 
            {
                while (!st.empty() && height[current] > height[st.top()]) 
                {
                    int top = st.top();
                    st.pop();
                    if (st.empty())
                        break;
                    int distance = current-st.top()-1;
                    int bounded_height = min(height[current], height[st.top()])-height[top];
                    water += distance*bounded_height;
                }
                st.push(current++);
            }
            return water;
        }
        // TC: 0(N)
        // SC: 0(N)
};
