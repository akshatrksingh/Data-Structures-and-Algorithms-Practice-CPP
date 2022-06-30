/*
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
    Node* rotate(Node* head, int k)
    {
        Node* connect = head;
        Node* curr = head;
        int count = 0;
        while(count < k-1)
        {
            curr = curr->next;
            count++;
        }
        if(curr->next == NULL)
        {
            return connect;
        }
        Node* rotated = curr->next;
        Node* temp = rotated;
        curr->next = NULL;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = connect;
        return rotated;
    }
};
