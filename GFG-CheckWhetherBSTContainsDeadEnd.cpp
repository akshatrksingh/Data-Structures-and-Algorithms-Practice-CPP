/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/


bool isDeadEndRecursion(Node *root, int min, int max)
{
    if(root == NULL)
    {
        return false;
    }
    if(min == max)
    {
        return true;
    }
    return isDeadEndRecursion(root->left, min, root->data-1) || isDeadEndRecursion(root->right, root->data+1, max);
}

bool isDeadEnd(Node *root)
{
    return isDeadEndRecursion(root, 1, INT_MAX);
}
