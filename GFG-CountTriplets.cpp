int countTriplets(Node* head, int x) 
{ 
    unordered_map <int, int> m;
    Node* curr = head;
    while(curr != NULL)
    {
        m[curr->data] = 1;
        curr = curr->next;
    }
    Node* t1 = head;
    Node* t2;
    int cnt = 0;
    while(t1->next->next != NULL)
    {
        t2 = t1->next;
        while(t2->next != NULL)
        {
           int target = x- t1->data - t2->data;
           if(target > t1->data && target > t2->data && m[target] == 1)
           {
               cnt++;
           }
           t2 = t2->next;
        }
        t1 = t1->next;
    }
    return cnt;
} 
