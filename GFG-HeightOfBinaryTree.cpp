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
    int height(struct Node* root)
    {
            // Level order traversal
            if (root == NULL) 
            return {};
            queue<Node*> q;
            q.push(root);
            int height = 0;
            while(true) 
            {
                int n = q.size();
                if(n == 0)
                    return height;
                height++;
                while(n > 0) 
                {
                    Node *node = q.front();
                    q.pop();

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    n--;
                }
            }
    }
};
