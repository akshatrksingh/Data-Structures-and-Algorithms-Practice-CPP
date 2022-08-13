class Solution 
{
    public:
        vector<string> letterCombinations(string digits) 
        {
            vector<string> answers = {""};
            vector<string> mapping = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            for(int i = 0; i < digits.size(); i++)
            {
                string characters = mapping[digits[i]-'2'];
                vector<string> temp;
                for(int j = 0; j < answers.size(); j++)
                {
                    for(int k = 0; k < characters.length(); k++)
                    {
                        temp.push_back(answers[j]+characters[k]);
                    }
                }
                answers = temp;
            }
            return (answers.size()==1)? vector<string>(): answers;
        }
};
