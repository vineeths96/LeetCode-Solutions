class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        std::stack<std::pair<int, int>> dfsStack;
        std::vector<std::vector<int>> imageCopy(image.begin(), image.end());

        if (imageCopy[sr][sc] == color)
            return imageCopy;

        int initialColor = imageCopy[sr][sc];        
        dfsStack.push(std::make_pair(sr ,sc)); 
        imageCopy[sr][sc] = color;

        while (!dfsStack.empty()) {
            auto top = dfsStack.top();
            dfsStack.pop();

            int x = top.first;
            int y = top.second;

            if (x > 0 && imageCopy[x-1][y] == initialColor) {
                dfsStack.push(std::make_pair(x - 1, y));
                imageCopy[x-1][y] = color;
            }

            if (x < imageCopy.size() - 1 && imageCopy[x+1][y] == initialColor) {
                dfsStack.push(std::make_pair(x + 1, y));
                imageCopy[x+1][y] = color;
            }

            if (y > 0 && imageCopy[x][y-1] == initialColor) {
                dfsStack.push(std::make_pair(x, y - 1));
                imageCopy[x][y-1] = color;
            }
            
            if (y < imageCopy[0].size() - 1 && imageCopy[x][y+1] == initialColor) {
                dfsStack.push(std::make_pair(x, y + 1));
                imageCopy[x][y+1] = color;
            }
        }

        return imageCopy;
    }
};