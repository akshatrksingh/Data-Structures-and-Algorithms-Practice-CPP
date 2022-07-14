/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    void inorder(Node* root, int width, int height, map<int, pair<int, int>> &m)
    {
        if(root == NULL) 
            return; 
    
        inorder(root->left, width-1, height+1, m);
        
        if(m.find(width) == m.end())
            m[width] = make_pair(root->data, height); 
        else if(m[width].second > height)
            m[width] = make_pair(root->data, height); 
        
        inorder(root->right, width+1, height+1, m);
    }
    vector<int> topView(Node* root)
    {
        if(root == NULL)
            return {};
            
        map<int, pair<int, int>> m;
        vector<int> v;
        inorder(root, 0, 0, m);
        for(auto i: m)
            v.push_back(i.second.first);
        return v;  
    }
    // TC: O(N log N)
    // SC: O(N)
};
