class Solution
{
    public:
    
    bool check(Node* root, int min, int max)
    {
        if(root == NULL)
        {
           return 1;
        }
        if(root->data < min || root->data > max)
        {
           return 0;
        }
        return(check(root->left, min, root->data) && check(root->right, root->data, max));
    }
   
    bool isBST(Node* root) 
    {
       return check(root, INT_MIN, INT_MAX);
    }
};
