class BrowserHistory 
{
    public:
        list<string> history;
        list<string>::iterator curr;
    
        BrowserHistory(string homepage) 
        {
            history.push_back(homepage);
            curr = history.begin();
        }

        void visit(string url) 
        {
            auto del = curr;
            del++;
            history.erase(del, history.end());
            history.push_back(url);
            curr++;
        }

        string back(int steps) 
        {
            while(curr != history.begin() && steps != 0)
            {
                curr--;
                steps--;
            }
            return *curr;
        }

        string forward(int steps) 
        {
            while(curr != --history.end() && steps != 0)
            {
                curr++;
                steps--;
            }
            return *curr;
        }
    
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
