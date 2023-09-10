class Solution
{
    public:
    
        Node* reverse(Node *head)
        {
            Node* prev = NULL;
            Node* curr = head;
            Node* forw = NULL;
            while(curr != NULL)
            {
                forw = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forw;
            }
            return prev;
        }
        
        Node* addOne(Node *head) 
        {
            head = reverse(head);
            Node* curr = head;
            Node* prev = NULL;
            int carry = 1;
            while(curr != NULL)
            {
                curr->data += carry;
                if(curr->data == 10)
                {
                    curr->data = 0;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                prev = curr;
                curr = curr->next;
            }
            if(carry == 1)
            {
                prev->next = new Node(1);
            }
            return reverse(head);
        }
};
