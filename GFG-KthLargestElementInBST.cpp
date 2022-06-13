class Solution
{
    public:
    vector<int> v;
    void reverseInorder(Node *root)
    {
    	if(root == NULL)
    	{
    		return;
    	}	
    	reverseInorder(root->right);
    	v.push_back(root->data);
    	reverseInorder(root->left);
    }
    int kthLargest(Node *root, int k)
    {
        reverseInorder(root);
        return v[k-1];
    }
};
