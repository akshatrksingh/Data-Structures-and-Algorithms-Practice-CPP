/*
struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
*/
class Solution
{
    public:
    bool detectLoop(Node* head)
    {
        unordered_set<Node*> s; 
        while (head != NULL) 
        { 
            if (s.find(head) != s.end()) 
                return true; 
      
            s.insert(head); 
            head= head->next; 
        } 
        return false;
  
        return false; 
    }
};
