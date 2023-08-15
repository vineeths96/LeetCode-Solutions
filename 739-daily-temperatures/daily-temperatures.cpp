class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> monotonicStack;
        std::vector<int> warmerTemperatureDays(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!monotonicStack.empty() && temperatures[i] > temperatures[monotonicStack.top()]) {
                warmerTemperatureDays[monotonicStack.top()] = i - monotonicStack.top();
                monotonicStack.pop();
            }
            
            monotonicStack.push(i);
        }

        return warmerTemperatureDays;
    }
};