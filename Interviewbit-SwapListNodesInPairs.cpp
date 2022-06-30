/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* head) 
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode* first = head;
    ListNode* second = head->next;
    first->next = swapPairs(head->next->next);
    second->next = first;
    return second;
};
