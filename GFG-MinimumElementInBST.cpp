int minValue(Node* root) 
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->left != NULL)
    {
        return minValue(root->left);
    }
    return root->data;
}
