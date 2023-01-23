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

/*
class Solution 
{
    public:
        int trap(vector<int> &height) 
        {
            int n = height.size();
            vector<int> leftMax(n), rightMax(n);
            leftMax[0] = 0;
            rightMax[n-1] = 0;
            for (int i = 1; i < n; ++i) 
            {
                leftMax[i] = max(height[i-1], leftMax[i-1]);
            }
            for (int i = n-2; i >= 0; --i) 
            {
                rightMax[i] = max(height[i+1], rightMax[i+1]);
            }
            int ans = 0;
            for (int i = 0; i < n; ++i) 
            {
                int waterLevel = min(leftMax[i], rightMax[i]);
                if (waterLevel >= height[i]) 
                {
                    ans += waterLevel - height[i];
                }
            }
            return ans;
        }
        // TC: 0(N)
        // SC: 0(N)
};
*/

class Solution 
{
    public:
        int trap(vector<int> &height) 
        {
            int n = height.size();
            int ans = 0, curr = 0;
            stack<int> st;
            while(curr < n)
            {
                while(!st.empty() && height[st.top()] < height[curr])
                {
                    int top = st.top();
                    st.pop();
                    if(st.empty())
                        break;
                    int distance = curr-st.top()-1;
                    int bounded_height = min(height[curr], height[st.top()])-height[top];
                    ans += distance*bounded_height;
                }
                st.push(curr++);
            }
            return ans;
        }
        // TC: 0(N)
        // SC: 0(N)
};
