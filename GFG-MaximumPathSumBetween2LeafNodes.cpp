/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

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
            if (isLeaf(node)) 
                return node->data;
            int d = node->data; 
            int l = modifyTree(node->left);
            int r = modifyTree(node->right);
            node->data = max(l, r);
            if(node->left && node->right)
            {
                mx = max(mx, d+l+r);
                return d+max(l, r);
            }
            return (node->left)? d+l: d+r;
        }
        int maxPathSum(Node* root)
        {
            mx = INT_MIN;
            // If the tree is right-most or left-most tree add a node with zero value
            if(root->left == NULL)
                root->left = new Node(0);
            if(root->right == NULL)
                root->right = new Node(0);
            modifyTree(root);
            return mx;
        }
};
