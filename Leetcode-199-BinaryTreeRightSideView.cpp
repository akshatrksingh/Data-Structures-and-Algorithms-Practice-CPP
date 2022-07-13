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
        vector<int> v;
        void rightSideViewRecursion(TreeNode* root, int level) 
        {
            if(root == NULL)
                return;
            if(v.size() == level)
                v.push_back(root->val);
            rightSideViewRecursion(root->right, level+1);
            rightSideViewRecursion(root->left, level+1);
        }
        vector<int> rightSideView(TreeNode* root) 
        {
            rightSideViewRecursion(root, 0);
            return v;
        }
};
