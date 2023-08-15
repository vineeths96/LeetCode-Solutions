class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int BASKET_COUNT = 2;
        std::unordered_map<int, int> typeFreqTracker;
        int maxFruitCount = std::numeric_limits<int>::min();

        for (int windowStart = 0, windowEnd = 0; windowEnd < fruits.size(); windowEnd++) {
            typeFreqTracker[fruits[windowEnd]]++;

            while (windowStart <= windowEnd && typeFreqTracker.size() > BASKET_COUNT) {
                typeFreqTracker[fruits[windowStart]]--;

                if (typeFreqTracker[fruits[windowStart]] == 0)
                    typeFreqTracker.erase(fruits[windowStart]);

                windowStart++;
            }

            maxFruitCount = std::max(maxFruitCount, windowEnd - windowStart + 1);
        }

        return maxFruitCount;
    }
};