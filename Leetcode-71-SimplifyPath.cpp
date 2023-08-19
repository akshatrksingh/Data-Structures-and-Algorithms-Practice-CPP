class Solution 
{
    public:
        string simplifyPath(string path) 
        {
            stack<string> st;
            string token;
            int i = 0;
            
            while(i < path.size())
            {
                while(i < path.size() && path[i] == '/')
                {
                    i++;
                }
                
                token = "";
                while(i < path.size() && path[i] != '/')
                {
                    token += path[i];
                    i++;
                }
                
                if(token != ".." && token != "." && token != "")
                {
                    st.push(token);
                }
                else if(token == "..")
                {
                    if(!st.empty())
                    {
                        st.pop();
                    }
                }
            }
            
            string res = "";
            while(!st.empty())
            {
                res = '/' + st.top() + res;
                st.pop();
            }
            
            if(res == "")
            {
                return "/";
            }
            return res;
        }
};
