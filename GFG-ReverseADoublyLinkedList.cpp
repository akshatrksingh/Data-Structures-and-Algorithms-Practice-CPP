/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
void swap(Node* node)
{
    Node* prev = node->prev;
    node->prev = node->next;
    node->next = prev;
}

Node* reverseDLL(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL)
    {
        swap(curr);
        prev = curr;
        curr = curr->prev;
    }
    return prev;
}
