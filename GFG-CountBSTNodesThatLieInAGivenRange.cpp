class Solution
{
    public:
    
        int cnt = 0;
        
        int getCount(Node *root, int l, int h)
        {
            if(root == NULL)
            {
                return 0;
            }
            if(root->data >= l && root->data <= h)
            {
                cnt++;
            }
            getCount(root->left, l, h);
            getCount(root->right, l, h);
            return cnt;
        }
};
