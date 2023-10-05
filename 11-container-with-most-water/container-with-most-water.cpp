class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = std::numeric_limits<int>::min();
        int start = 0;
        int end = height.size() - 1;

        while (start < end) {
            int containerHeight = std::min(height[start], height[end]);
            int containerWater = containerHeight * (end - start);
            maxWater = std::max(maxWater, containerWater);

            height[start] < height[end] ? start++ : end--;
        }

        return maxWater;
    }
};