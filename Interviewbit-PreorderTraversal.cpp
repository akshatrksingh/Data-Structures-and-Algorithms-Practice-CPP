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
vector<int> v;
void func(TreeNode* root)
{
    if(root == NULL)
        return;
    v.push_back(root->val) ;
    func(root->left);
    func(root->right);
}

vector<int> Solution::preorderTraversal(TreeNode* root) 
{
    v.clear();
    func(root) ;
    return v ;
}
