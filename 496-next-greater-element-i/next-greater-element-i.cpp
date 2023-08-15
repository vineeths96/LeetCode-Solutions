class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::stack<int> monotonicStack;
        std::unordered_map<int, int> ngeTracker;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!monotonicStack.empty() &&  nums2[i] >= monotonicStack.top())
                monotonicStack.pop();

            ngeTracker[nums2[i]] = monotonicStack.empty() ? -1 : monotonicStack.top();
            monotonicStack.push(nums2[i]);
        }

        std::vector<int> ngeVector;
        for (const auto &num : nums1)
            ngeVector.push_back(ngeTracker[num]);

        return ngeVector;
    }
};