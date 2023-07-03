class Solution 
{
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) 
        {
            vector<string> result;
            int n = words.size();
            int i = 0;

            while (i < n) 
            {
                int lineLength = words[i].size();
                int j = i + 1;

                // Find the last word that can fit in the current line
                while (j < n && lineLength + 1 + words[j].size() <= maxWidth) 
                {
                    lineLength += 1 + words[j].size();
                    j++;
                }

                int numWords = j - i;  // Number of words in the current line
                int numSpaces = maxWidth - lineLength + numWords - 1;  // Total number of spaces to be added

                // Create the current line
                string line = words[i];

                // If it's the last line or only one word in the line, left justify the line
                if (j == n || numWords == 1) 
                {
                    for (int k = i + 1; k < j; k++) 
                    {
                        line += " " + words[k];
                    }
                    line += string(maxWidth - line.size(), ' ');  // Add extra spaces to make the line maxWidth
                } 
                else 
                {
                    int avgSpaces = numSpaces / (numWords - 1);  // Average spaces to be added between words
                    int extraSpaces = numSpaces % (numWords - 1);  // Extra spaces to be added to the left slots
                    int cnt = 1;
                    
                    for (int k = i + 1; k < j; k++) 
                    {
                        int spaces = (cnt++ <= extraSpaces) ? avgSpaces + 1 : avgSpaces;
                        line += string(spaces, ' ') + words[k];
                    }
                }

                result.push_back(line);
                i = j;  // Move to the next line
            }

            return result;
        }
    };
