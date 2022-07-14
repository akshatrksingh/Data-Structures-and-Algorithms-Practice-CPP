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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
        {
            if (root == NULL) 
                return {};
            queue<TreeNode *> q;
            vector<int> v1;
            vector<vector<int>> v2;
            q.push(root);
            int level = 0;
            while (!q.empty()) 
            {
                int n = q.size();  // # Nodes in the current level
                while(n > 0) 
                {
                    TreeNode *node = q.front();
                    v1.push_back(node->val);
                    q.pop();

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    n--;
                }
                if(level % 2 == 1)
                    reverse(v1.begin(), v1.end());
                v2.push_back(v1);
                v1.clear();
                level++;
            }
            return v2;
        }
};
