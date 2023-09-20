class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
        std::unordered_map<int, int> outgoingMap;

        for (int i = 0; i < k; i++) {
            if (maxHeap.empty() || nums[i] <= maxHeap.top()) 
                maxHeap.push(nums[i]);
            else
                minHeap.push(nums[i]);
 
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }

        std::vector<double> medians;
        medians.push_back(k & 1 ? maxHeap.top() : (0.5 * minHeap.top() + 0.5 * maxHeap.top()));

        for (int i = k; i < nums.size(); i++) {
            int balance = 0;
            int outgoingNumber = nums[i - k];
            outgoingMap[outgoingNumber]++;

            if (outgoingNumber <= maxHeap.top()) balance++;
            else balance--;
  
            if (nums[i] <= maxHeap.top()) {
                maxHeap.push(nums[i]);
                balance--;
            } else {
                minHeap.push(nums[i]);
                balance++;
            }
 
            if (balance > 0) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else if (balance < 0) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            while (!maxHeap.empty() && outgoingMap[maxHeap.top()]) {
                outgoingMap[maxHeap.top()]--;
                maxHeap.pop();
            }

            while (!minHeap.empty() && outgoingMap[minHeap.top()]) {
                outgoingMap[minHeap.top()]--;
                minHeap.pop();
            }
            
            medians.push_back(k & 1 ? maxHeap.top() : (0.5 * minHeap.top() + 0.5 * maxHeap.top())); 
        }

        return medians;
    }
};