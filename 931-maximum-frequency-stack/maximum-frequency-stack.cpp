class FreqStack {
    struct Compare {
        bool operator()(const std::vector<int> &A, const std::vector<int> &B) {
            return A[1] < B[1] || A[1] == B[1] && A[2] < B[2]; 
        }
    };

    int sequenceNumber;
    std::unordered_map<int, int> freqMap;
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Compare> maxHeap;

public:
    FreqStack() {
      sequenceNumber = 0;  
    }
    
    void push(int val) {
        maxHeap.push({val, ++freqMap[val], sequenceNumber++});
    }
    
    int pop() {
        int val = maxHeap.top()[0];
        maxHeap.pop();
        freqMap[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */