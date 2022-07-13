class Solution
{
  public:
    int minDepth(Node *root) 
    {
            if (root == NULL) return {};
            queue<Node*> q;
            q.push(root);
            int minDepth = 0;
            while (!q.empty()) 
            {
                int n = q.size();
                minDepth++;
                while(n > 0) 
                {
                    Node *node = q.front();
                    q.pop();
                    
                    if(node->left == NULL &&  node->right == NULL)
                        return minDepth;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    n--;
                }
            }
    }
};
