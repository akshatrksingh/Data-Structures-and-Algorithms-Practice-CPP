class Solution 
{
    public:
        ListNode* reverse(ListNode* head)
        {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = NULL;
            while(curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            l1 = reverse(l1);
            l2 = reverse(l2);
            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;
            int carry = 0;
            while (l1 != NULL || l2 != NULL || carry != 0) 
            {
                int a = (l1 == NULL) ? 0: l1->val;
                int b = (l2 == NULL) ? 0: l2->val;
                int sum = a + b + carry;
                carry = sum / 10;
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
                if(l1 != NULL)
                    l1 = l1->next;
                if(l2 != NULL)
                    l2 = l2->next;
            }
            return reverse(dummy->next);
        }
};
