/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//Function to return a list containing the postorder traversal of the tree.
    vector <int> postOrder(Node* root)
    {
        vector<int> v;
        stack<Node*> st;
        if(root == NULL)
            return {};
        st.push(root);
        while(!st.empty()) 
        {
            root = st.top();
            st.pop();
            v.push_back(root->data);
            if(root->left != NULL) 
                st.push(root->left);
            if(root->right != NULL) 
                st.push(root->right);
        }
        reverse(v.begin(), v.end());
        return v;
    }
