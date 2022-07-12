/* A binary tree node has data, pointer to left child
   and a pointer to right child  

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

//Function to return a list containing the preorder traversal of the tree.
    vector <int> preorder(Node* root)
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
            if(root->right != NULL) 
                st.push(root->right);
            if(root->left != NULL) 
                st.push(root->left);
        }
        return v;
    }
