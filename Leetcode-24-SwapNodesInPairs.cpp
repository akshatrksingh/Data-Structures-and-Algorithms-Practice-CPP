class Solution 
{
    public:
        ListNode* swapPairs(ListNode* head) 
        {
            if(head == NULL || head->next == NULL)
            {
                return head;
            }
            
            ListNode* dummyNode = new ListNode(-1);
            ListNode* prevNode = dummyNode;
            ListNode* currNode = head;

            while(currNode != NULL && currNode->next != NULL)
            {
                prevNode->next = currNode->next;
                currNode->next = prevNode->next->next;
                prevNode->next->next = currNode;

                prevNode = currNode;
                currNode = currNode->next;
            }
            return dummyNode->next;
        }
};
