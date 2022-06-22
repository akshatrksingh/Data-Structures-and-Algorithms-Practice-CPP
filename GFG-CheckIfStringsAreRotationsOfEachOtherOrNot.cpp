class Solution
{
    public:
    bool areRotations(string str1, string str2)
    {
        if (str1.size() != str2.size())
        {
            return false;
        }
        str1 += str1;
        return str1.find(str2) != string::npos;
        
    }
};
