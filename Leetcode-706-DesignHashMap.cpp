class MyHashMap 
{
    public:
        vector<list<pair<int, int>>> h;
        int sz;
    
        MyHashMap() 
        {
            sz = 100;
            h.resize(sz);
        }
        
        int hash(int key)
        {
            return key%sz;
        }
        
        list<pair<int, int>>::iterator search(int key)
        {
            int i = hash(key);
            for(auto it = h[i].begin(); it !=h[i].end(); it++)
            {
                if(it->first == key)
                    return it;
            }
            return h[i].end();    
        }
    
        void put(int key, int val) 
        {
            int i = hash(key);
            remove(key);
            h[i].push_back({key, val});
        }

        int get(int key) 
        {
            int i = hash(key);
            auto it = search(key);
            if(it != h[i].end())
                return it->second;
            else
                return -1;
        }

        void remove(int key) 
        {
            int i = hash(key);
            auto it = search(key);
            if(it != h[i].end())
                h[i].erase(search(key));
        }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
