class Solution
{
    public:
    int n, c;
    bool flag = true;
    void inorder(Node *root, int k)
    {
    	if(root == NULL)
    	{
    		return;
    	}	
    	inorder(root->left, k);
    	c++;
    	if(c == k) 
    	{
    	    n = root->data;
    	    flag = false;
    	    return;
    	}
    	inorder(root->right, k);
    }
    int KthSmallestElement(Node *root, int k)
    {
        c = 0;
        inorder(root, k);
        if(flag) return -1;
        return n;
    }
};
