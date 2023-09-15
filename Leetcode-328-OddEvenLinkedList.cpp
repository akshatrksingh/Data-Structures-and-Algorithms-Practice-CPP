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
        ListNode* oddEvenList(ListNode* head) 
        {
            ListNode* dummy1 = new ListNode(-1);
            ListNode* dummy2 = new ListNode(-1);
            ListNode* curr = head;
            ListNode* odd = dummy1;
            ListNode* even = dummy2;
            int c = 1;
            while(curr != NULL)
            {
                if(c % 2 == 0)
                {
                    even->next = curr;
                    even = even->next;
                }
                else
                {
                    odd->next = curr;
                    odd = odd->next;
                }
                curr = curr->next;
                c++;
            }
            odd->next = dummy2->next;
            even->next = NULL;
            return dummy1->next;
        }
};
