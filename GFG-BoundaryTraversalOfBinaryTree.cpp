/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution 
{
    public:
        vector<int> v;
        vector<int> v_left, v_leaf, v_right;
        bool isLeaf(Node *node) 
        {
            return (node->left == NULL) && (node->right == NULL);
        }
        void left(Node *node)
        {
            while(node)
            {
                if(!isLeaf(node))
                    v_left.push_back(node->data);   
                if(node->left)
                    node = node->left;
                else
                    node = node->right;
            }
        }
        void leaf(Node *node)
        {
            if(node == NULL)
                return;
            if(isLeaf(node))
                v_leaf.push_back(node->data);
            if(node->left)
                leaf(node->left);
            if(node->right)
                leaf(node->right);
        }
        void right(Node *node)
        {
            while(node)
            {
                if(!isLeaf(node))
                    v_right.push_back(node->data);   
                if(node->right)
                    node = node->right;
                else 
                    node = node->left;
            }
            reverse(v_right.begin(), v_right.end());
        }
        vector<int> boundary(Node *root)
        {
            if(root == NULL)
                return {};
            if(!isLeaf(root))
                v.push_back(root->data);
            left(root->left);
            leaf(root);
            right(root->right);  
            for(int i: v_left)
                v.push_back(i);
            for(int i: v_leaf)
                v.push_back(i);
            for(int i: v_right)
                v.push_back(i);
            return v;
        }
};
