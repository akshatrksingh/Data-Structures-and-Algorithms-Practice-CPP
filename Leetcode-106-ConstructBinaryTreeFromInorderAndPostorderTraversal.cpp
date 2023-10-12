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

        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
        {
            return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        }
    
    private:
    
        TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) 
        {
            // Base case: If any of the arrays is empty, return nullptr
            if (postStart > postEnd || inStart > inEnd) 
            {
                return NULL;
            }
            
            int rootValue = postorder[postEnd];
            TreeNode* root = new TreeNode(rootValue);
            
            // Find the root index in inorder
            int rootIndex;
            for(int i = inStart; i <= inEnd; i++)
            {
                if(inorder[i] == rootValue)
                {
                    rootIndex = i;
                }
            }
            
            // Recursively construct left and right subtrees
            int leftSubtreeSize = rootIndex - inStart;
            root->left = buildTreeHelper(inorder, inStart, rootIndex-1, postorder, postStart, postStart+leftSubtreeSize-1);
            root->right = buildTreeHelper(inorder, rootIndex+1, inEnd, postorder, postStart+leftSubtreeSize, postEnd-1);
            
            return root;
        }
};
