class MyStack 
{
public:
       
    queue<int> q1;
    queue<int> q2;
    
    MyStack() 
    {
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        q1.push(x);
        q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int a;
        queue<int> q4;
        queue<int> q5 = q2;
        while(!q5.empty())
        {
            a = q5.front();
            q5.pop();
            if(!q5.empty())
            {
                q4.push(a);
            }
        }
        q1 = q4;
        q2 = q4;
        return a;        
    }
    
    /** Get the top element. */
    int top() 
    {
        queue<int> q3 = q1;
        int a;
        while(!q3.empty())
        {
            a = q3.front();
            q3.pop();
        }
        return a;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return q1.empty() ;  
    }
};
