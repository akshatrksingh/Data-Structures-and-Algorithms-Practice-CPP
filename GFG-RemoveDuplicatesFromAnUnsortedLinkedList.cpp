/*
struct Node 
{
  int data;
  struct Node *next;
  Node(int x) 
  {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
        Node* removeDuplicates(Node* head) 
        {
            unordered_map<int, int> m;
            Node* prev = NULL;
            Node* curr = head;
            while (curr != NULL) 
            {
                if(m.count(curr->data) == 0)
                {
                    m[curr->data]++;
                    prev = curr;
                    curr = curr->next; 
                }
                else
                {
                    prev->next = curr->next;
                    curr = prev->next;
                }
            }
            return head;
        }
};
