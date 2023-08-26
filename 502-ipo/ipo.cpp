class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        std::priority_queue<int, std::vector<int>, std::less<int>> profitHeap;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> capitalHeap;

        for (int i = 0; i < capital.size(); i++)
            capitalHeap.push({capital[i], i});

        for (int i = 0; i < k; i++) {
            while (!capitalHeap.empty() && capitalHeap.top().first <= w) {
                profitHeap.push(profits[capitalHeap.top().second]);
                capitalHeap.pop();
            }

            if (profitHeap.empty()) break;

            w += profitHeap.top();
            profitHeap.pop();
        }

        return w;
    }
};