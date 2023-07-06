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

class Trie 
{
    private:
        TrieNode* root;

    public:
        Trie() 
        {
            root = new TrieNode();
        }

        void insert(string word) 
        {
            TrieNode* current = root;
            for (char ch : word) 
            {
                if (current->children.find(ch) == current->children.end()) 
                {
                    current->children[ch] = new TrieNode();
                }
                current = current->children[ch];
            }
            current->isEndOfWord = true;
        }

        bool search(string word) 
        {
            TrieNode* current = root;
            for (char ch : word) 
            {
                if (current->children.find(ch) == current->children.end()) 
                {
                    return false;
                }
                current = current->children[ch];
            }
            return current->isEndOfWord;
        }

        bool startsWith(string prefix) 
        {
            TrieNode* current = root;
            for (char ch : prefix) 
            {
                if (current->children.find(ch) == current->children.end())
                {
                    return false;
                }
                current = current->children[ch];
            }
            return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
