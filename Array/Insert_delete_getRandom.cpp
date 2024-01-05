class RandomizedSet {
public:
   vector<int>v;
   unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        else{
            v.push_back(val);
            mp[val]=v.size()-1;
            return true;
        }         
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            int last_val=v.back();  //v[v.size()-1];
            v[mp[val]]=last_val;
            v.pop_back();
            mp[last_val]=mp[val];
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

