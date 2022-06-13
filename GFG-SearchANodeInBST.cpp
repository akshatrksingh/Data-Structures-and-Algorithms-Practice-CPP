bool search(Node* root, int x) 
{
    if(root == NULL)
    {
        return 0;
    }
    else if(x == root->data)
    {
        return 1;
    }
    else if(x < root->data)
    {
        search(root->left, x);
    }
    else
    {
        search(root->right, x);
    }
}
