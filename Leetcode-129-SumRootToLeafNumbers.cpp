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
    
        vector<string> num;
    
        bool isLeaf(TreeNode* root)
        {
            if(root->left == NULL && root->right == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
        void sumNumbersHelper(TreeNode* root, string s) 
        {
            if(root == NULL)
            {
                return;
            }
            else if(isLeaf(root))
            {
                num.push_back(s+to_string(root->val));
            }
            else
            {
                sumNumbersHelper(root->left, s+to_string(root->val));
                sumNumbersHelper(root->right, s+to_string(root->val));
            }
        }
    
        int sumNumbers(TreeNode* root) 
        {
            string s = "";
            sumNumbersHelper(root, s);
            int sum = 0;
            for(string n: num)
            {
                sum += stoi(n);
            }
            return sum;
        }
};
