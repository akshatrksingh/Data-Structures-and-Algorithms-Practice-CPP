Node *removeDuplicates(Node *head)
{
    Node* copy = head;
    while(head->next != NULL)
    {
        Node* temp = head->next;
        if(head->data == temp->data)
        {
            head->next = temp->next;
            delete temp;
        }
        else
        {
            head = head->next;
        }
    }
    return copy;
}
