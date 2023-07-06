class TrieNode
{
    public:
        bool isEndOfWord;
        unordered_map<char, TrieNode*> children;
        TrieNode()
        {
            isEndOfWord = false;
        }
};

class Solution 
{
    private:
        TrieNode* root;
    
    public:
    
        void insert(string word)
        {
            TrieNode* curr = root;
            for(char ch: word)
            {
                if(curr->children.find(ch) == curr->children.end())
                {
                    curr->children[ch] = new TrieNode();
                }
                curr = curr->children[ch];
            }
            curr->isEndOfWord = true;
        }
        
        bool isBuildable(string word)
        {
            TrieNode* curr = root;
            for(char ch: word)
            {
                if(curr->children[ch]->isEndOfWord == false)
                {
                    return false;
                }
                curr = curr->children[ch];
            }
            return true;
        }
    
        string longestWord(vector<string>& words) 
        {
            root = new TrieNode();
            for(string &word: words)
            {
                insert(word);
            }
            string longestWord = "";
            for (string& word: words) 
            {
                if (word.length() > longestWord.length() || (word.length() == longestWord.length() && word < longestWord)) 
                {
                    if (isBuildable(word)) 
                    {
                        longestWord = word;
                    }
                }
            }

        return longestWord;
        }
};
