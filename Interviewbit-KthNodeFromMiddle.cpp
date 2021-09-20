/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int lenOfList(ListNode* head)
{
    int len = 1;
    while(head->next != NULL)
	{
        len++;
        head = head->next;
	}
    return len;
}

int Solution::solve(ListNode* A, int B) 
{
    int N = lenOfList(A);
    int pos = (N/2 + 1 - B) - 1;
    if(pos < 0)
        return -1;
    for(int i = 0; i < pos; i++)
	{
        A = A->next;
	}
    return A->val;
}
