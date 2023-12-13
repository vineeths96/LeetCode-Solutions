class RandomizedSet {
    std::unordered_map<int, int> numMap;
    std::vector<int> numVec;

public:
    RandomizedSet() {
        numMap = std::unordered_map<int, int>();
        numVec = std::vector<int>();
    }
    
    bool insert(int val) {
        if (numMap.contains(val)) return false;

        numMap.insert({val, numVec.size()});
        numVec.push_back(val);

        return true;
    }
    
    bool remove(int val) {
        if (!numMap.contains(val)) return false;
        
        int lastNum = numVec.back();
        int removeIndex = numMap[val];

        std::swap(numVec[removeIndex], numVec.back());
        numVec.pop_back();

        numMap[lastNum] = removeIndex;
        numMap.erase(val);

        return true;
    }
    
    int getRandom() {
        int index = std::rand() % numVec.size();
        return numVec[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */