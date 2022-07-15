/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution
{
    public:
    int areMirror(Node* a, Node* b) 
    {
        if(a == NULL && b == NULL)
            return true;
        else if(a == NULL || b == NULL)
            return false;
        else if(a->data != b->data)
            return false;
        return areMirror(a->left, b->right) && areMirror(a->right, b->left);
    }
};
