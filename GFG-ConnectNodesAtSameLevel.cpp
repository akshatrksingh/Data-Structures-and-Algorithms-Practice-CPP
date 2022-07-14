/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    void connect(Node* root)
    {
            if (root == NULL) 
                return;
            queue<Node*> q;
            vector<Node*> v;
            q.push(root);
            while (!q.empty()) 
            {
                int n = q.size();  // # Nodes in the current level
                while(n > 0) 
                {
                    Node* node = q.front();
                    v.push_back(node);
                    q.pop();

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    n--;
                }
                for(int i = 1; i < v.size(); i++)
                {
                    v[i-1]->nextRight = v[i];
                }
                v.clear();
            }
    }    
      
};
