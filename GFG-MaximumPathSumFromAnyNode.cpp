class Solution 
{
  public:
        int mx;
        bool isLeaf(Node* node)
        {
            if(node->left || node->right)
                return false;
            return true;
        }
        int modifyTree(Node* node)
        {
            if(node == NULL)
                return 0;
            int d = node->data; 
            int l = max(0, modifyTree(node->left));
            int r = max(0, modifyTree(node->right));
            node->data = max(l, r);
            mx = max(mx, d+l+r);
            return d+max(l, r);
        }
        int findMaxSum(Node* root)
        {
            mx = INT_MIN;
            modifyTree(root);
            return mx;
        }
};
