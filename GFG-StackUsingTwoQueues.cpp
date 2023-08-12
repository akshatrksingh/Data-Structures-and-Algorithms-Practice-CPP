/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* 
// Making pop() costly
void QueueStack :: push(int x)
{
    q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty())
    {
        return -1;
    }
    while(q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int x = q1.front();
    q1.pop();
    while(q2.size())
    {
        q1.push(q2.front());
        q2.pop();
    }
    return x;
}
*/

// Making push() costly
void QueueStack :: push(int x)
{
    while(q1.size())
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(x);
    while(q2.size())
    {
        q1.push(q2.front());
        q2.pop();
    }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty())
    {
        return -1;
    }
    int x = q1.front();
    q1.pop();
    return x;
}
