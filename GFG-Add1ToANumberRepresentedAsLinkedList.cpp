/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
        Node* reverse(Node* head)
        {
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;
            while(curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
        Node* addOne(Node* head) 
        {
            head = reverse(head);
            Node* curr = head;
            Node* prev = NULL;
            int sum, carry = 1;
            while(curr != NULL)
            {   
                sum = curr->data + carry;
                curr->data = (sum == 10)? 0: sum;
                carry = (sum == 10)? 1: 0;
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
