class FreqStack {
    int maxFrequency;
    std::unordered_map<int, int> freqMap;
    std::unordered_map<int, std::stack<int>> freqStackMap;

public:
    FreqStack() {
        maxFrequency = 0;
    }
    
    void push(int val) {
        freqMap[val]++;
        freqStackMap[freqMap[val]].push(val);
        maxFrequency = std::max(maxFrequency, freqMap[val]);
    }
    
    int pop() {
        int top = freqStackMap[maxFrequency].top();
        freqStackMap[maxFrequency].pop();
        freqMap[top]--;

        if (freqStackMap[maxFrequency].empty()) {
            freqStackMap.erase(maxFrequency);
            maxFrequency--;
        }

        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */