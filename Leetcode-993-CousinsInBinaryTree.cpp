/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    public:
        bool isCousins(TreeNode* root, int x, int y) 
        {
            if (root == NULL) 
                return false;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) 
            {
                int n = q.size();  // # Nodes in the current level
                int c = 0;
                while(n > 0) 
                {
                    TreeNode *node = q.front();
                    q.pop();
                    
                    if(node->val == x || node->val == y)
                    {
                        c++;
                        if(c == 2)
                        return true;
                    }
                    if(node->left && node->right)   // siblings in upcoming level
                        if(node->left->val == x && node->right->val == y || node->left->val == y && node->right->val == x)
                            return false;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    n--;
                }
            }
            return false;
        }
};
