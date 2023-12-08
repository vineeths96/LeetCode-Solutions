class Solution {
public:
    int nthUglyNumber(int n) {
        std::set<long> countedNums;
        std::priority_queue<long, std::vector<long>, std::greater<long>> minHeap;

        int count = 0;
        minHeap.push(1);
        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            
            count++;
            if (count == n) return top;
            
            if (!countedNums.contains(top * 2)) {
                countedNums.insert(top * 2);
                minHeap.push(top * 2);
            }

            if (!countedNums.contains(top * 3)) {
                countedNums.insert(top * 3);
                minHeap.push(top * 3);
            }

            if (!countedNums.contains(top * 5)) {
                countedNums.insert(top * 5);
                minHeap.push(top * 5);
            }
        }

        return -1;
    }
};