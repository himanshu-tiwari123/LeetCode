class RandomizedSet {
public:
    vector<int>arr;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(mp.count(val)){
           
            return false;
        }

        arr.push_back(val);
        mp[val] = arr.size()-1;

        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            
           return false;
        }else{
            int index = mp[val];
            
            int n = arr.size();
            mp[arr[n-1]] = index;
            mp.erase(mp.find(val));
            swap(arr[index],arr[n-1]);
            
            arr.pop_back();
           
            return true;
        }

    }
    
    int getRandom() {
        int idx = rand()%arr.size();
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */