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

        bool isValidBSTRecursion(TreeNode* root, long min, long max) 
        {
            if(root == NULL)
            {
                return true;
            }
            else if(root->val > min && root->val < max)
            {
                return isValidBSTRecursion(root->left, min, root->val) && isValidBSTRecursion(root->right, root->val, max);
            }
            else
            {
                return false;
            }
        }

        bool isValidBST(TreeNode* root) 
        {
            if(root == NULL)
            {
                return true;
            }
            if(root->left && root->left->val >= root->val)
            {
                return false;
            }
            if(root->right && root->right->val <= root->val)
            {
                return false;
            }
            return isValidBSTRecursion(root->left, (long)INT_MIN-1, root->val) && isValidBSTRecursion(root->right, root->val, (long)INT_MAX+1);
        }
};
