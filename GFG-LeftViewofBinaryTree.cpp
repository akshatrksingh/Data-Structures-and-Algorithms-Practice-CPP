/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
        if (root == NULL) return {};
        queue<Node*> q;
        vector<int> v1;
        vector<vector<int>> v2;
        vector<int> v3;
        q.push(root);
        while (!q.empty()) 
        {
            int n = q.size();
            while(n > 0) 
            {
                Node *node = q.front();
                v1.push_back(node->data);
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                n--;
            }
            v2.push_back(v1);
            v1.clear();
        }
        //Above part is level order traversal
        for(auto v: v2)
        {
            v3.push_back(v[0]);
        }
    return v3;
}
