/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
        Node* insertionSort(Node* head)
        {
            if (head == NULL || head->next == NULL)
            {
                return head;
            }
    
            Node* sortedList = NULL; 
            Node* curr = head;    // Current node to be inserted
    
            while (curr != NULL)
            {
                Node* forw = curr->next;  // Store the next node in the original list
                sortedList = insert(sortedList, curr);  // Insert the current node into the sorted list
                curr = forw;  // Move to the next node in the original list
            }
    
            return sortedList;
        }
    
        // Helper function to insert a node into a sorted linked list
        Node* insert(Node* sortedList, Node* newNode)
        {
            if (sortedList == NULL|| newNode->data <= sortedList->data)
            {
                newNode->next = sortedList;
                return newNode;
            }
    
            Node* curr = sortedList;
    
            while (curr->next!= NULL && curr->next->data < newNode->data)
            {
                curr = curr->next;
            }
    
            newNode->next = curr->next;
            curr->next = newNode;
    
            return sortedList;
        }
};
