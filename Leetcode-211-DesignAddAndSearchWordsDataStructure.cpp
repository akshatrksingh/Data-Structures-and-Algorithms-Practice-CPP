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
            TrieNode *curr = root;
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

        bool search(string word) 
        {
            return searchRecursive(word, 0, root);
        }

        bool searchRecursive(const string& word, int index, TrieNode* node)
        {
            if (index == word.length()) 
            {
                return node->isEndOfWord;
            }

            char ch = word[index];

            if (ch != '.') 
            {
                if (node->children.find(ch) == node->children.end()) 
                {
                    return false;
                }
                return searchRecursive(word, index + 1, node->children[ch]);
            } 
            else 
            {
                for (auto& kvp : node->children) 
                {
                    if (searchRecursive(word, index + 1, kvp.second)) 
                    {
                        return true;
                    }
                }
            }

            return false;
        }
};

class WordDictionary 
{
    private:
        Trie trie;

    public:
        WordDictionary() 
        {
        }

        void addWord(string word) 
        {
            trie.insert(word);
        }

        bool search(string word) 
        {
            return trie.search(word);
        }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
