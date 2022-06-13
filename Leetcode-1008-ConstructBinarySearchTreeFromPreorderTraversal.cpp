class Solution 
{
    public:
        TreeNode* newNode(int val)
        {
            TreeNode* newNode = new TreeNode;
            newNode->val = val;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        int build(vector<int> &preorder, int n, int pos, TreeNode* curr, int left, int right)
        {
            if(pos == n || preorder[pos] < left || preorder[pos] > right) return pos;

            if(preorder[pos] < curr->val)
            {
                curr->left = newNode(preorder[pos]);
                pos++;
                pos = build(preorder, n, pos, curr->left, left, curr->val-1);
            }

            if(pos == n || preorder[pos] < left || preorder[pos] > right) return pos;

            if(preorder[pos] > curr->val)
            {
                curr->right = newNode(preorder[pos]);
                pos++;
                pos = build(preorder, n, pos, curr->right, curr->val+1, right);
            }

            return pos;
        }

        TreeNode* bstFromPreorder(vector<int>& preorder) 
        {
            int n = preorder.size();
            if(n == 0) return NULL;

            TreeNode* root = newNode(preorder[0]);
            if(n == 1) return root;

            build(preorder, n, 1, root, INT_MIN, INT_MAX);
            return root;
        }
};
