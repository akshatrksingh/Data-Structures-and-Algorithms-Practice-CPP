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
        TreeNode* maxValueNode(TreeNode* node)
        {
            TreeNode* curr = node;
            while (curr && curr->right)
            {
                curr = curr->right;
            }
            return curr;
        }
        TreeNode* deleteNode(TreeNode* root, int key) 
        {
            if(root == NULL)
            {
                return NULL;
            }
            else if(key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            else if(key > root->val)
            {
                root->right = deleteNode(root->right, key); 
            }
            else
            {
                // leaf node
                if(root->left == NULL && root->right == NULL)
                {
                    return NULL;
                }
                // node with one child
                else if(root->left == NULL)
                {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
                // node with one child
                else if(root->right == NULL)
                {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                // node with two children
                else
                {
                    /*
                     replace with maxValueNode in left subtree 
                     OR
                     replace with minValueNode in right subtree 
                     */
                    TreeNode* temp = maxValueNode(root->left);
                    root->val = temp->val;
                    root->left = deleteNode(root->left, temp->val);
                }
            }
            return root;
        }
};
