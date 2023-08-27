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
        ListNode* reverseKGroup(ListNode* head, int k) 
        {
            ListNode* temp = head;
            int cnt = 0;
            while(cnt < k)
            {
                if(temp == NULL)
                {
                    return head;
                }
                temp = temp->next;
                cnt++;
            }
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* forw = NULL;
            cnt = 0;
            while(curr != NULL && cnt < k)
            {
                forw = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forw;
                cnt++;
            }
            if(forw != NULL)
            {
                head->next = reverseKGroup(forw, k);
            }
            return prev;
        }
};
