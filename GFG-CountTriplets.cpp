int countTriplets(struct Node* head, int x) 
{ 
    unordered_map<int, int> m;
    Node* curr = head;
    while (curr != NULL)
    {
        m[curr->data] = 1;
        curr = curr->next;
    }
    if (m.size() < 3)
    {
        return 0;
    }
    
    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* slow = dummy->next;
    Node* fast = dummy->next->next;
    
    int count = 0;
    
    while (slow != NULL)
    {
        fast = slow->next;
        while (fast != NULL)
        {
            int remaining_sum = x - (slow->data + fast->data);
            
            if (m.find(remaining_sum) != m.end() && remaining_sum != slow->data && remaining_sum != fast->data)
            {
                count++;
            }
            
            fast = fast->next;
        }
        
        slow = slow->next;
    }
    
    return count / 3; // Each triplet is counted three times, so divide by 3 to get distinct triplets.
}
