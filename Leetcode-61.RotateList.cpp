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
class Solution 
{
    public:
        ListNode* rotateRight(ListNode* head, int k) 
        {
            if(head == NULL)
            {
                return head;
            }
            int len = 0;
            ListNode* curr = head;
            while(curr != NULL)
            {
                curr = curr->next;
                len++;
            }
            k = k % len;
            if(k == 0)
            {
                return head;
            }
            ListNode* prevRotated = head;
            for(int i = 0; i < len-k-1; i++)
            {
                prevRotated = prevRotated->next;
            }
            ListNode* rotated = prevRotated->next;
            prevRotated->next = NULL;
            curr = rotated;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = head;
            return rotated;
        }
};
