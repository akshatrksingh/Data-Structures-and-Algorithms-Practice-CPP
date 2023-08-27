/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
class Solution 
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            if(head == NULL)
            {
                return head;
            }
            int len = 0;
            ListNode* curr = head;
            while(curr != NULL)
            {
                len++;
                curr = curr->next;
            }
            int k = len-n;
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            ListNode* prev = dummy;
            while(k--)
            {
                prev = prev->next;
            }
            ListNode* temp;
            temp = prev->next;
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
            return dummy->next;
        }
};
*/
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;
        while(--n)
        {
            fast = fast->next;
        }
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
