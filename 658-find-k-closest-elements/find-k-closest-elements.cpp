class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::deque<int> closestElements;
        
        int lowerBound = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int lowerIndex = lowerBound - 1;
        int higherIndex = lowerBound;

        while (k) {
            if (lowerIndex >= 0 && (higherIndex >= arr.size() || std::abs(arr[lowerIndex] - x) <= std::abs(arr[higherIndex] - x)))
                closestElements.push_front(arr[lowerIndex--]);
            else
                closestElements.push_back(arr[higherIndex++]);

            k--;
        }

        return std::vector<int>(closestElements.begin(), closestElements.end());
    }
};