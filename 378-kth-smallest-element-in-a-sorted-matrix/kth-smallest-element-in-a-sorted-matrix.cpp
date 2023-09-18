class Solution {
    struct Compare {
        bool operator()(const std::pair<int, std::pair<int, int>> &A, const std::pair<int, std::pair<int, int>> &B) {
            return A.first > B.first;
        }
    };

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, Compare> minHeap;
        for (int i = 0; i < matrix.size(); i++)
            if (!matrix[i].empty())
                minHeap.push({matrix[i][0], {i, 0}});
        
        int index = 0;
        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();

            if (++index == k) return top.first;
            
            top.second.second++;
            if (top.second.second < matrix[top.second.first].size())
                minHeap.push({matrix[top.second.first][top.second.second], {top.second.first, top.second.second}}); 
        }

        return -1;
    }
};