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
class Solution {
public:
    int maxDepth(TreeNode *root)
    {   
        if (root == NULL) 
            return 0;
        if (root->left == NULL && root->right == NULL) 
            return 1;

        if (root->left == NULL) 
            return maxDepth(root->right) + 1;
        if (root->right == NULL) 
            return maxDepth(root->left) + 1;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1; 
    };
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL) return true;
        if(maxDepth(root->left)-maxDepth(root->right) != 0 && abs(maxDepth(root->left)-maxDepth(root->right)) != 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
