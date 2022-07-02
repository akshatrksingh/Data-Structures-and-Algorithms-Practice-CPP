/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution
{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        if(!head) 
            return -1;
        vector<Node*> v = {head};
        while (v.back()->next != NULL)
        {
            v.push_back(v.back()->next);
        }
        return v[v.size() / 2]->data;
    }
};
