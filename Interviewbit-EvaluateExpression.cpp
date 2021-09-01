bool isnum(string str)
{

    for (auto c = str.begin(); c < str.end(); c++) 
    {
        if(c == str.begin() && *c == '-' && str.size() > 1)
            continue;
        else if(!isdigit(*c)) 
            return false;
    }
    return true;
}

int op(int a, int b, string s)
{
    if(s == "+")
        return a+b;
    else if(s == "-")
        return a-b;
    else if(s == "*")
        return a*b;
    else 
        return a/b;
}

int Solution::evalRPN(vector<string> &v) 
{
    if(v.size() == 1)
        return stoi(v[0]);
    stack<int> st;
    int res = 0, a, b;
    for(auto it = v.begin(); it < v.end(); it++)
    {
        if(isnum(*it))
        {
            st.push(stoi(*it));
        }
        else
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            res = op(b, a, *it);
            st.push(res);
        }
    }
    return res;
}

