/**
 * Definition for binary tree
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* r1, TreeNode* r2) 
{
    if(r1 == NULL && r2 == NULL)
        return 1;

    if(r1 == NULL || r2 == NULL)
        return 0;

    return isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right) && (r1->val == r2->val);
}
