/*
// Recursion: TLE
class Solution 
{
    public:
    
        bool wordBreakRecursion(string s, unordered_set<string>& w) 
        {
            if(s == "")
            {
                return true;
            }
            for(int i = 0; i <= s.size(); i++)
            {
                if(w.count(s.substr(0, i)) && wordBreakRecursion(s.substr(i), w))
                {
                    return true;
                }
            }
            return false;
        }
        
        bool wordBreak(string s, vector<string>& v) 
        {
            unordered_set<string> w(v.begin(), v.end());
            return wordBreakRecursion(s, w);
        }
        
        // TC: 0(2^N) 
        // T(N) = T(N-1) + T(N-2) + ... + T(0)
        // T(N-1) = T(N-2) + ... + T(0)
        // T(N) - T(N-1) = T(N-1)
        // T(N) = 2*T(N-1)
        // T(N-1) = 2*T(N-2) and so on
        // T(N) = 2 * 2 * .... 2 * T(0) {n} times => ~ 2^N => O(2^N)
        // SC: O(N) for recursive stack
        // Overlapping subproblems
        // Input: 
        // "aaaab"
        // ["a","aa","aaa", "aaaa"]
        
};
*/

/*
// Recursion with memoization: AC
class Solution 
{
    public:
        bool wordBreakRecursion(string s, unordered_set<string>& w, unordered_map<string, bool>& memo) 
        {
            if (s == "") 
            {
                return true;
            }

            if (memo.count(s)) 
            {
                //cout<<s<<" ";
                return memo[s]; // If the result for the current string is already memoized, return it
            }

            for (int i = 0; i <= s.size(); i++) 
            {
                if (w.count(s.substr(0, i)) && wordBreakRecursion(s.substr(i), w, memo)) 
                {
                    return memo[s] = true; // Memoize the result for the current string
                }
            }

            memo[s] = false; 
            return false;
        }

        bool wordBreak(string s, vector<string>& v) 
        {
            unordered_set<string> w(v.begin(), v.end());
            unordered_map<string, bool> memo;
            return wordBreakRecursion(s, w, memo);
        }
    
        // TC: O(N^2)
        // SC: O(N) for recursive stack
};
*/

/*
// Trie and recursion : TLE
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

        void insert(string &word) 
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

        bool canWordBreak(string &s, int start, TrieNode* curr) 
        {
            int n = s.length();

            if (start == n) 
            {
                return true; // Reached the end of the string
            }

            for (int i = start; i < n; i++) 
            {
                char ch = s[i];
                if (curr->children.find(ch) == curr->children.end()) 
                {
                    break; // Invalid prefix, break the loop
                }
                curr = curr->children[ch];
                if (curr->isEndOfWord && canWordBreak(s, i + 1, root)) 
                {
                    return true;
                }
            }

            return false;
        }

    public:
        bool wordBreak(string s, vector<string>& wordDict) 
        {
            root = new TrieNode();
            for (string word : wordDict) 
            {
                insert(word);
            }
            return canWordBreak(s, 0, root);
        }
};

*/

// Trie and recursion with memoization : AC
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
        unordered_map<int, bool> memo; // Memoization map to store results

        void insert(string &word) 
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

        bool canWordBreak(string &s, int start, TrieNode* curr) 
        {
            int n = s.length();

            if (start == n) 
            {
                return true; // Reached the end of the string
            }

            if (memo.find(start) != memo.end()) 
            {
                return memo[start]; // Return memoized result if available
            }

            for (int i = start; i < n; i++) 
            {
                char ch = s[i];
                if (curr->children.find(ch) == curr->children.end()) 
                {
                    break; // Invalid prefix, break the loop
                }
                curr = curr->children[ch];
                if (curr->isEndOfWord && canWordBreak(s, i + 1, root)) 
                {
                    memo[start] = true; // Memoize the result
                    return true;
                }
            }

            memo[start] = false; // Memoize the result
            return false;
        }

    public:
        bool wordBreak(string s, vector<string>& wordDict) 
        {
            root = new TrieNode();
            for (string word : wordDict) 
            {
                insert(word);
            }
            return canWordBreak(s, 0, root);
        }
};

























