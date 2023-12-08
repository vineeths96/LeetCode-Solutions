class RandomizedSet {
    std::unordered_set<int> randSet;

public:
    RandomizedSet() {
        randSet = std::unordered_set<int>();  
    }
    
    bool insert(int val) {
        return randSet.insert(val).second;
    }
    
    bool remove(int val) {
        return randSet.erase(val) == 1;
    }
    
    int getRandom() {
        int index = std::rand() % randSet.size();
        auto iterator = randSet.begin();
        for (int i = 0; i < index; i++)
            iterator++;

        return *iterator;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */