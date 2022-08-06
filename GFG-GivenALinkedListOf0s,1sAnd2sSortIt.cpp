/*
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
        Node* segregate(Node* head) 
        {
            Node* curr = head;
            int count0 = 0, count1 = 0, count2 = 0;
            while(curr != NULL)
            {
                if(curr->data == 0)
                {
                    count0++;
                }
                else if(curr->data == 1)
                {
                    count1++;
                }
                else if(curr->data == 2)
                {
                    count2++;
                }
                curr = curr->next;
            }
            Node* seg = head;
            while(count0--)
            {
                seg->data = 0;
                seg = seg->next;
            }
            while(count1--)
            {
                seg->data = 1;
                seg = seg->next;
            }
            while(count2--)
            {
                seg->data = 2;
                seg = seg->next;
            }
            return head;
        }
};
