Node *deleteNode(Node *root, int X) 
{
    if(root == NULL)
	{
		return NULL;
	}
	else if(X < root->data)
	{
		root->left = deleteNode(root->left, X);
		return root;
	}
	else if(X == root->data)
	{
		//Leaf node
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		//Node with 1 child
		else if(root->left != NULL && root->right == NULL)
		{
			Node *tmp = root->left;
			delete root;
			return tmp;
		}
		else if(root->left == NULL && root->right != NULL)
		{
			Node *tmp = root->right;
			delete root;
			return tmp;
		}
		//Node with 2 children
		else 
		{
			Node *replace = root->right;
			//inorder successor from right subtree
			while(replace->left != NULL)
			{
				replace = replace->left;
			}
			root->data = replace->data;
			root->right = deleteNode(root->right, replace->data);
			return root;
		}
	}
	else
	{
		root->right = deleteNode(root->right, X);
		return root;
	}
}
