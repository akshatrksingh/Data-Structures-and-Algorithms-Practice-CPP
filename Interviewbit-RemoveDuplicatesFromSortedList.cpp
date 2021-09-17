/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *Solution::deleteDuplicates(ListNode *head) 
{
    ListNode *cpy = head;
    while(head->next != NULL)
	{
        ListNode *tmp;
        tmp = head->next;
        if(head->val == tmp->val)
        {
            head->next = tmp->next;
            delete tmp;
        }
        else
        {
            head = head->next;
        }
	}
    return cpy;
}
