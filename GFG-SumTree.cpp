*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
        bool isLeaf(Node *node)
        {
            if(node->left == NULL && node->right == NULL)
                return true;
            return false;
        }
        bool isSumTree(Node* node)
        {
            int leftSum; 
            int rightSum; 
         
            if(node == NULL || isLeaf(node))
                return true;
         
            if(isSumTree(node->left) && isSumTree(node->right))
            {
                if(node->left == NULL)
                    leftSum = 0;
                else if(isLeaf(node->left))
                    leftSum = node->left->data;
                else
                    leftSum = 2*(node->left->data);
         
                if(node->right == NULL)
                    rightSum = 0;
                else if(isLeaf(node->right))
                    rightSum = node->right->data;
                else
                    rightSum = 2*(node->right->data);
         
                return(node->data == leftSum + rightSum);
            }
            
            return false;
        }
};
