/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target)
    {
        vector<pair<int, int>> v;
        Node* left = head;
        Node* right = head;
        while(right->next != NULL)
        {
            right = right->next;
        }
        while(left->data < right->data)
        {
            if(left->data + right->data == target)
            {
                v.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return v;
    }
};
