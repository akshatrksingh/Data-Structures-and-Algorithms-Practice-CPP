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
        ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) 
        {
            ListNode *m = new ListNode(-1);
            ListNode *n = m;
            while(list1 && list2)
            {
                if(list1->val < list2->val)
                {
                    m->next = list1;
                    list1 = list1->next;
                }
                else
                {
                    m->next = list2;
                    list2 = list2->next;
                }
                m = m->next;
            }
            if(list1)
            {
                m->next = list1;
            }
            else if(list2)
            {
                m->next = list2;
            }
            
            return n->next;
        }
        ListNode *mergeKLists(vector<ListNode*> &lists) 
        {
            if(lists.size() == 0) 
                return NULL;
            ListNode* head = lists[0];
            for (int i = 1; i < lists.size(); i++)
            {
                head = mergeTwoLists(head, lists[i]);
            }
            
            return head;
        }
};
