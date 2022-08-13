int checkValidSegment(string seg)
{
    int n = stoi(seg);
    if((seg.size() > 1 && seg[0] == '0') || n > 255)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int checkValidString(string s)
{
    stringstream check1(s);
    string intermediate;
    while(getline(check1, intermediate, '.'))
    {
        if(checkValidSegment(intermediate) == 0)
        {
            return 0;
        }
    }
    return 1;
}

vector<string> Solution::restoreIpAddresses(string A) 
{
    vector<string> s;
    string str1, str2, str3;
    if(A.size() < 4 || A.size() > 12)
    {
        return s;
    }
    else 
    {
        for(int i = 1; i < A.size(); i++)
        {
            str1 = A;
            str1.insert(i, ".");
            for(int j = i+2; j < str1.size(); j++)
            {
                str2 = str1;
                str2.insert(j, ".");
                for(int k = j+2; k < str2.size(); k++)
                {
                    str3 = str2;
                    str3.insert(k, ".");
                    if(checkValidString(str3) == 1)
                    {
                        s.push_back(str3);
                    }
                }
            }
        }
    }
    return s;
}
