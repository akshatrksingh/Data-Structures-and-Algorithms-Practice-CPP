class Solution
{
    public:
        Node* lowestCommonAncestor(Node* root, int p, int q) 
        {
            if(root == NULL || root->data == p || root->data == q) 
                return root;
            Node* l = lowestCommonAncestor(root->left, p, q);
            Node* r = lowestCommonAncestor(root->right, p, q);
            if(l != NULL && r != NULL) 
                return root;
            return(l != NULL) ? l : r;
        }
        int findDistRecursion(Node* root, int n, int level)
        {
            if(root == NULL)
                return -1;
            if(root->data == n)
                return level;
            else
            {
                int left = findDistRecursion(root->left, n, level+1);
                int right = findDistRecursion(root->right, n, level+1);
                return (left != -1) ? left : right;
            }
        }
        int findDist(Node* root, int a, int b) 
        {
            Node* lca = lowestCommonAncestor(root, a, b);
            int adist = findDistRecursion(root, a, 0);
            int bdist = findDistRecursion(root, b, 0);
            int lcadist = findDistRecursion(root, lca->data, 0);
            return adist + bdist - 2*lcadist;
        }
};
