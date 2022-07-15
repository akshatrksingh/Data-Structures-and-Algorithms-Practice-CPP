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
        TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) 
        {
            if(root == NULL || root->val == p || root->val == q) 
                return root;
            TreeNode* l = lowestCommonAncestor(root->left, p, q);
            TreeNode* r = lowestCommonAncestor(root->right, p, q);
            if(l != NULL && r != NULL) 
                return root;
            return(l != NULL) ? l : r;
        }
        bool traverse(TreeNode* root, string &path, int v) 
        {
            if(root == NULL)
                return false;
        
            if(root->val == v) 
                return true;
        
            path.push_back('L');
            if(traverse(root->left, path, v)) 
                return true; 
            path.pop_back();  

            path.push_back('R');
            if(traverse(root->right, path, v)) 
                return true; 
            path.pop_back(); 

            return false;
        }

        string getDirections(TreeNode* root, int startValue, int destValue) 
        {
            TreeNode* lca = lowestCommonAncestor(root, startValue, destValue);

            string lca_to_start = "", lca_to_dest = "";
            traverse(lca, lca_to_start, startValue);
            traverse(lca, lca_to_dest, destValue);

            for(auto &c : lca_to_start) 
                c = 'U';

            return lca_to_start + lca_to_dest;
        }
};
