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
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
        {
            return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        }

    private:
    
        TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) 
        {
            // Base case: If any of the arrays is empty, return nullptr
            if (preStart > preEnd || inStart > inEnd) 
            {
                return NULL;
            }

            // The first element of preorder is the root value
            int rootValue = preorder[preStart];
            TreeNode* root = new TreeNode(rootValue);

            // Find the root index in inorder
            int rootIndex;
            for (int i = inStart; i <= inEnd; i++) 
            {
                if (inorder[i] == rootValue) 
                {
                    rootIndex = i;
                    break;
                }
            }

            // Recursively construct left and right subtrees
            int leftSubtreeSize = rootIndex - inStart;
            root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, inorder, inStart, rootIndex - 1);
            root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd);

            return root;
        }
};
