class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(sticks.begin(), sticks.end());

        int totalCost = 0;
        while (minHeap.size() > 1) {
            int firstStick = minHeap.top();
            minHeap.pop();
            int secondStick = minHeap.top();
            minHeap.pop();

            int currentStick = firstStick + secondStick;
            totalCost += currentStick;
            minHeap.push(currentStick);
        }

        return totalCost;
    }
};