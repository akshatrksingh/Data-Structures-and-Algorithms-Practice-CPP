/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
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

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) 
{
    int N = lenOfList(A);
    int pos;
    ListNode *cpy = A;
    ListNode *tmp;
    if(B < N)
    {
        pos = N-B;
        for(int i = 0; i < pos-1; i++)
	    {
            A = A->next;
        }
        tmp = A->next;
        A->next = tmp->next;
        delete tmp;
        return cpy;
    }
    else
    {
        tmp = A;
        A = tmp->next;
        return A;
    }
}
