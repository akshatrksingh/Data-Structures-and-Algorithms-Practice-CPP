class Solution 
{
    public:
        int minMutation(string startGene, string endGene, vector<string>& bank) 
        {
            unordered_set<string> geneBank(bank.begin(), bank.end());
            if (geneBank.find(endGene) == geneBank.end()) 
            {
                return -1; 
            }

            queue<string> q;
            q.push(startGene);
            int mutations = 0;
            string genes = "ACGT"; // Possible characters for gene mutation

            while (!q.empty()) 
            {
                int qSize = q.size();
                while (qSize--) 
                {
                    string currentGene = q.front();
                    q.pop();

                    if (currentGene == endGene) 
                    {
                        return mutations; 
                    }

                    for (int i = 0; i < currentGene.length(); i++) 
                    {
                        char originalChar = currentGene[i];
                        for (char c : genes) 
                        {
                            if (c == originalChar) 
                                continue; // Skip the original character
                            currentGene[i] = c; // Make the mutation
                            if (geneBank.find(currentGene) != geneBank.end()) 
                            {
                                q.push(currentGene); // If the mutation is in the bank, add it to the queue for further exploration.
                                geneBank.erase(currentGene); // Remove the gene from the bank to avoid revisiting it.
                            }
                        }
                        currentGene[i] = originalChar; // Revert back to the original gene for the next iteration.
                    }
                }
                mutations++; // Increment the number of mutations at each level of BFS.
            }

            return -1; // If we can't reach the endGene, return -1.
        }
};
