class Solution 
{
    public:
        map<Node*, Node*> oldToNew; 
        Node* cloneGraph(Node* node) 
        {
            if(node == NULL) 
            {
                return NULL;
            }
            if(oldToNew.find(node) == oldToNew.end()) 
            {
                oldToNew[node] = new Node(node -> val, {}); 
                for(auto nbr: node->neighbors) 
                {
                    oldToNew[node]->neighbors.push_back(cloneGraph(nbr)); 
                }
            }
            return oldToNew[node]; 
        }
};
