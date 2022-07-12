/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution 
{
  public:
    vector<int> inOrder(Node* root) 
    {
        vector<int> v;
        stack<Node*> st;
        while(root != NULL || !st.empty()) 
        {
            while(root != NULL) 
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            v.push_back(root->data);
            root=root->right;
        }
        return v;
    }
};
