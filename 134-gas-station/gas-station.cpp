class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startStation = 0;
        int currentGain = 0;
        int totalGain = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGain += gas[i] - cost[i];
            currentGain += gas[i] - cost[i];

            if (currentGain < 0) {
                currentGain = 0;
                startStation = i + 1;
            }
        }

        return totalGain >= 0 ? startStation : -1; 
    }
};