class Solution {
    struct Compare {
        bool operator()(const std::vector<int> &A, const std::vector<int> &B) {
            return A[0] + A[1] < B[0] + B[1];
        }
    };

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Compare> maxHeap;
        for (const int &firstNum : nums1) {
            for (const int &secondNum : nums2) {
                if (maxHeap.size() < k)
                    maxHeap.push({firstNum, secondNum});
                else {
                    int sum = firstNum + secondNum;
                    int maxHeapTopSum = maxHeap.top()[0] + maxHeap.top()[1]; 

                    if (sum > maxHeapTopSum)
                        break;
                    else {
                        maxHeap.pop();
                        maxHeap.push({firstNum, secondNum});
                    }
                }
            }
        }

        std::vector<std::vector<int>> kSmallestPairs;
        while (!maxHeap.empty()) {
            kSmallestPairs.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return kSmallestPairs;
    }
};