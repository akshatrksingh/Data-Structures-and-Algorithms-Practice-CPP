class RandomizedSet 
{
    public:
        
        vector<int> v;
        unordered_map <int, int> m;
        
        RandomizedSet() 
        {
        }

        bool insert(int val) 
        {
            if(m.find(val) == m.end())
            {
                v.push_back(val);
                m[val] = v.size()-1;    // index of val in v
                return true;
            }
            return false;
        }

        bool remove(int val) 
        {
            if(m.find(val) != m.end())
            {
                auto it = m.find(val);
                v[it->second] = v.back();
                v.pop_back();
                m[v[it->second]] = it->second;
                m.erase(val);
                return true;
            }
            return false;
        }

        int getRandom() 
        {
            return v[rand()%v.size()];
        }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
