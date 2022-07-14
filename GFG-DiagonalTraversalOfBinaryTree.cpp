/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void diagonalRecursion(Node* root, int diagRow, map<int, vector<int>> &m)
{
    if(root == NULL)
        return;
    m[diagRow].push_back(root->data);
    diagonalRecursion(root->left, diagRow+1, m);
    diagonalRecursion(root->right, diagRow, m);
}

vector<int> diagonal(Node *root)
{
    map<int, vector<int>> m;
    vector<int> v;
    diagonalRecursion(root, 0, m);
    for(auto x: m)
        for(auto node: x.second)
            v.push_back(node);
    return v;
}
