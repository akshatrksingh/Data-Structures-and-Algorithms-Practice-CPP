struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution 
{
    public:
    
        Node* mergeTwoLists(Node* list1, Node* list2) 
        {
            Node* merged = new Node(0);
            Node* curr = merged;
            while(list1 != NULL && list2 != NULL)
            {
                if(list1->data < list2->data)
                {
                    curr->bottom = list1;
                    list1 = list1->bottom;
                }
                else
                {
                    curr->bottom = list2;
                    list2 = list2->bottom;
                }
                curr = curr->bottom;
            }
            if(list1 != NULL)
            {
                curr->bottom = list1;
            }
            if(list2 != NULL)
            {
                curr->bottom = list2;
            }
            return merged->bottom;
        }
        
        Node *flatten(Node *root)
        {
            if(root == NULL)
            {
                return root;
            }
            root->next = flatten(root->next);
            root = mergeTwoLists(root, root->next);
            return root;
        }
};
