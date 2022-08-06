class Solution
{
    public:
        ListNode* moveToFront(ListNode* head)
        {
            if(head == NULL|| head->next == NULL)
            {
                return head;
            }
            ListNode* temp = head;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            ListNode* newHead = temp->next;
            temp->next = NULL;
            newHead->next = head;
            return newHead;
        }
};
