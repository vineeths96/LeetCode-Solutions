class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> maxHeap;

        for (const int &num : arr) {
            int distance = std::abs(num - x);
            
            if (maxHeap.size() < k) 
                maxHeap.push({distance, num});
            else {
                if (distance < maxHeap.top().first) {
                    maxHeap.pop();
                    maxHeap.push({distance, num});
                }
            }
        }

        std::vector<int> closestElements;
        while (!maxHeap.empty()) {
            auto kvPair = maxHeap.top();
            maxHeap.pop();
            closestElements.push_back(kvPair.second);
        }

        std::sort(closestElements.begin(), closestElements.end());

        return closestElements;
    }
};