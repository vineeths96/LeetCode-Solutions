class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        std::unordered_map<std::string, int> inDegrees;
        std::unordered_map<std::string, std::vector<std::string>> graph;

        for (const auto& ingredientList : ingredients) {
            for (const auto& ingredient : ingredientList) {
                inDegrees[ingredient] = 0;
                graph[ingredient] = std::vector<std::string>();
            }
        }

        for (const auto& recipe : recipes) {
            inDegrees[recipe] = 0;
            graph[recipe] = std::vector<std::string>();
        }

        for (int i = 0; i < recipes.size(); i++) {
            for (int j = 0; j < ingredients[i].size(); j++) {
                inDegrees[recipes[i]]++;
                graph[ingredients[i][j]].push_back(recipes[i]);
            }
        }

        std::queue<std::string> topoSortQueue;
        for (const auto &supply : supplies)
            topoSortQueue.push(supply);

        std::set<std::string> recipesSet(recipes.begin(), recipes.end());
        std::vector<std::string> recipesCreated;

        while (!topoSortQueue.empty()) {
            auto front = topoSortQueue.front();
            topoSortQueue.pop();

            if (recipesSet.contains(front))
                recipesCreated.push_back(front);

            for (const auto &neighbour : graph[front]) {
                inDegrees[neighbour]--;
                if (inDegrees[neighbour] == 0)
                    topoSortQueue.push(neighbour);
            }
        }

        return recipesCreated;
    }
};