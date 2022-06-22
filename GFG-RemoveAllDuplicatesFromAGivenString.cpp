class Solution
{
    public:
    	string removeDuplicates(string str) 
    	{
    	    unordered_map<char, int> freq;
    	    string res = "";
    	    for(char c: str)
    	    {
    	        freq[c]++;
    	        if(freq[c]==1) 
    	        {
    	            res += c;
    	        }
    	    }
    	    return res;
    	}
};
