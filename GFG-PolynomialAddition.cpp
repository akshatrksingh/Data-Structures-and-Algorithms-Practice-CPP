/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

class Solution
{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node* addPolynomial(Node *p1, Node *p2)
    {
        Node* res = new Node(0, 0);
        Node* curr = res;
        while(p1 != NULL || p2 != NULL)
        {
            if(p1 == NULL)
            {
                curr->next = new Node(p2->coeff, p2->pow);
                p2 = p2->next;
            }
            else if(p2 == NULL)
            {
                curr->next = new Node(p1->coeff, p1->pow);
                p1 = p1->next;
            }
            else
            {
                if(p1->pow == p2->pow)
                {
                    curr->next = new Node(p1->coeff + p2->coeff, p1->pow);
                    p1 = p1->next;
                    p2 = p2->next;
                }
                else if(p1->pow > p2->pow)
                {
                    curr->next = new Node(p1->coeff, p1->pow);
                    p1 = p1->next;
                }
                else
                {
                    curr->next = new Node(p2->coeff, p2->pow);
                    p2 = p2->next;
                }
            }
            curr = curr->next;
        }
        return res->next;
    }
};
