class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        std::multiset<int> maxHeap;
        std::multiset<int> minHeap;

        std::vector<double> medians;
        for (int i = 0; i < nums.size(); i++) {
            if (maxHeap.empty() || nums[i] <= *maxHeap.rbegin())
                maxHeap.insert(nums[i]);
            else 
                minHeap.insert(nums[i]);

            if (i >= k) {
                int outgoingNumber = nums[i-k];
                if (outgoingNumber <= *maxHeap.rbegin()) 
                    maxHeap.erase(maxHeap.find(outgoingNumber));
                else
                    minHeap.erase(minHeap.find(outgoingNumber)); 
            }

            if (maxHeap.size() < minHeap.size()) {    
                maxHeap.insert(*minHeap.begin());
                minHeap.erase(minHeap.begin());
            } else if (maxHeap.size() > minHeap.size() + 1) {    
                minHeap.insert(*maxHeap.rbegin());
                maxHeap.erase(std::prev(maxHeap.end()));
            }

            if (i >= k - 1)
                medians.push_back(k & 1 ? *maxHeap.rbegin() : 0.5 * *maxHeap.rbegin() + 0.5 * *minHeap.begin());
        }

        return medians;
    }
};