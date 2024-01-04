class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> leftMax(height.size(), -1);
        std::vector<int> rightMax(height.size(),-1);

        for (int i = 1; i < height.size(); i++)
            leftMax[i] = std::max(leftMax[i - 1], height[i - 1]);
        
        for (int i = height.size() - 2; i >= 0; i--)
            rightMax[i] = std::max(rightMax[i + 1], height[i + 1]);

        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            int waterHeight = std::min(leftMax[i], rightMax[i]) - height[i];
            water += std::max(waterHeight, 0);
        }

        return water;
    }
};