/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution 
{
  public:
    void mirror(Node* root) 
    {
            if (root == NULL) 
                return;
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) 
            {
                int n = q.size();  
                while(n > 0) 
                {
                    Node *node = q.front();
                    q.pop();

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    Node* temp = node->right;
                    node->right = node->left;
                    node->left = temp;
                    n--;
                }
            }
    }
};
