/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
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
            v3.push_back(v.back());
        }
    return v3;    }
};
