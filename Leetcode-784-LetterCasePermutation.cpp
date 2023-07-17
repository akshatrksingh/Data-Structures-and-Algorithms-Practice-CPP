class Solution 
{
    public:
        vector<string> letterCasePermutation(string s) 
        {
            set<string> uniqueCombinations;
            int n = s.length();
            int totalCombinations = 1 << n;

            for (int mask = 0; mask < totalCombinations; mask++) 
            {
                string combination = s;
                for (int i = 0; i < n; i++) 
                {
                    if (isalpha(combination[i])) 
                    {
                        if ((mask >> i) & 1) 
                        {
                            combination[i] = toupper(combination[i]);
                        } 
                        else 
                        {
                            combination[i] = tolower(combination[i]);
                        }
                    }
                }
                uniqueCombinations.insert(combination);
            }
            
            vector<string> result(uniqueCombinations.begin(), uniqueCombinations.end());
            return result;
        }
};
