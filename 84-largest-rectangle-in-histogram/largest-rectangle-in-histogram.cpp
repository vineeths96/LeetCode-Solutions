class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> monotonicStack;
        monotonicStack.push(-1);

        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (monotonicStack.top() != -1 && heights[monotonicStack.top()] > heights[i]) {
                int top = monotonicStack.top();
                monotonicStack.pop();

                int currentArea = heights[top] * (i - monotonicStack.top() - 1);
                area = std::max(area, currentArea);
            }

            monotonicStack.push(i);
        }

        int lastIndex = monotonicStack.top();
        while (monotonicStack.top() != -1) {
            int top = monotonicStack.top();
            monotonicStack.pop();

            int currentArea = heights[top] * (lastIndex - monotonicStack.top()); 
            area = std::max(area, currentArea);
        }

        return area;
    }
};