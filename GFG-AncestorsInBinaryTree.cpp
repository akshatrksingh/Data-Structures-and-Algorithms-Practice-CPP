/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution
{
  public:
        bool traverse(struct Node* root, vector<int> &v, int d) 
        {
            if(root == NULL)
                return false;
        
            if(root->data == d) 
                return true;
            
            v.push_back(root->data);
            if(traverse(root->left, v, d)) 
                return true; 
            v.pop_back();

            v.push_back(root->data);
            if(traverse(root->right, v, d)) 
                return true; 
            v.pop_back();

            return false;
        }
        vector<int> Ancestors(struct Node* root, int target)
        {
            vector<int> v;
            traverse(root, v, target);
            reverse(v.begin(), v.end());
            return v;
        }
};
