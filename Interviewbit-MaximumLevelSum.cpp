/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* root) 
{
    stack<TreeNode*> st;
    st.push(root);
    int c, sum, max_sum = 0;
    while(!st.empty())
    {
        c = st.size();
        sum = 0;
        stack<TreeNode*> s;
        while(c--)
        {
            TreeNode* node = st.top();
            st.pop();
            sum += node->val;
            if(node->left != NULL)
            {
                s.push(node->left);
            }
            if(node->right != NULL)
            {
                s.push(node->right);
            }
        } 
        st = s;       
        max_sum = max(max_sum, sum);
    }

    return max_sum;
}
