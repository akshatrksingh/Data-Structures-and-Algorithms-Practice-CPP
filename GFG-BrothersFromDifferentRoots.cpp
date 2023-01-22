/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
        
        unordered_set <int> s;
        int cnt = 0;
        
        void inorder1(Node* root)
        {
            if(root == NULL)
            {
                return;
            }
            inorder1(root->left);
            s.insert(root->data);
            inorder1(root->right);
        }
        
        void inorder2(Node* root, int x)
        {
            if(root == NULL)
            {
                return;
            }
            inorder2(root->left, x);
            if(s.find(x-root->data) != s.end())
            {
                cnt++;
            }
            inorder2(root->right, x);
        }
        
        int countPairs(Node* root1, Node* root2, int x)
        {
            inorder1(root1);
            inorder2(root2, x);
            return cnt;
        }
};
