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
        ListNode* middleNode(ListNode* head) 
        {
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast != NULL && fast->next != NULL) 
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            if (fast)                         // if the length of the list is odd, fast->next will be NULL but fast will not be NULL, in this case increase the mid by 1 node
            slow = slow->next;
            return slow;
            
        }
        ListNode* reverseList(ListNode* head)
        {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = NULL;
            while(curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
        bool isPalindrome(ListNode* head) 
        {
            if(head == NULL || head->next == NULL)
                return true;
            if(head->next->next == NULL)
                return head->val == head->next->val;
            
            ListNode* mid = middleNode(head);
            mid = reverseList(mid);
            while(mid != NULL)
            {
                if(head->val != mid->val)
                    return false;
                head = head->next;
                mid = mid->next;
            }
            return true;
        }
};
