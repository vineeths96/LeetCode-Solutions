class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;

        std::unordered_map<char, int> stringMap;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bulls++;
            else {
                if (stringMap[secret[i]] < 0) cows++;
                if (stringMap[guess[i]] > 0) cows++;
                
                stringMap[secret[i]]++;
                stringMap[guess[i]]--;
            }
        }
        
        return std::to_string(bulls) + "A" + std::to_string(cows) + "B"; 
    }
};