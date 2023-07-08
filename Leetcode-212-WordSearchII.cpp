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
    public:

        TrieNode* root;

        Trie() 
        {
            root = new TrieNode();
        }

        void insert(string word) 
        {
            TrieNode* curr = root;
            for (char ch : word) 
            {
                if (curr->children.find(ch) == curr->children.end()) 
                {
                    curr->children[ch] = new TrieNode();
                }
                curr = curr->children[ch];
            }
            curr->isEndOfWord = true;
        }
};

class Solution 
{
    private:
        vector<string> result;
        int rows, cols;

    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
        {
            rows = board.size();
            cols = board[0].size();

            Trie trie;
            for (const string& word : words) 
            {
                trie.insert(word);
            }

            for (int i = 0; i < rows; i++) 
            {
                for (int j = 0; j < cols; j++) 
                {
                    dfs(board, i, j, "", trie.root);
                }
            }

            return result;
        }

        void dfs(vector<vector<char>>& board, int row, int col, string currentWord, TrieNode* trieNode) 
        {
            if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] == '#') 
            {
                return;
            }

            char ch = board[row][col];
            if (trieNode->children.find(ch) == trieNode->children.end()) 
            {
                return;
            }

            currentWord += ch;
            trieNode = trieNode->children[ch];

            if (trieNode->isEndOfWord) 
            {
                result.push_back(currentWord);
                trieNode->isEndOfWord = false; 
            }

            board[row][col] = '#'; // Mark cell as visited

            dfs(board, row + 1, col, currentWord, trieNode); // Check cell below
            dfs(board, row - 1, col, currentWord, trieNode); // Check cell above
            dfs(board, row, col + 1, currentWord, trieNode); // Check cell to the right
            dfs(board, row, col - 1, currentWord, trieNode); // Check cell to the left

            board[row][col] = ch; // Restore cell

        }
};
