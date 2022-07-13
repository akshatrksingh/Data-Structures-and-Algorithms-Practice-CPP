void isCousinsRecursion(Node* node, int depth, int parent, unordered_map<int, pair<int, int>> &m) 
{
    if (node == NULL) 
        return;
    m[node->data] = make_pair(depth, parent);
    isCousinsRecursion(node->left, depth + 1, node->data, m);
    isCousinsRecursion(node->right, depth + 1, node->data, m);
}
bool isCousins(Node* root, int x, int y) 
{
	unordered_map<int, pair<int, int>> m;
	isCousinsRecursion(root, 0, -1, m);
	return m[x].first == m[y].first && m[x].second != m[y].second;
}
