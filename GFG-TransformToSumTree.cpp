/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution 
{
  public:
    int solve(Node* node)
    {
        if(node == NULL)
            return 0;
        int d = node->data; 
        int l = solve(node->left);
        int r = solve(node->right);
        node->data = l+r;
        return d+l+r;
    }
    void toSumTree(Node* root)
    {
        solve(root);
    }
};
