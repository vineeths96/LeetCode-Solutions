class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;

        std::unordered_map<char, int> secretMap;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bulls++;
            else
                secretMap[secret[i]]++;
        }

        for (int j = 0; j < guess.size(); j++) {
            if (secret[j] == guess[j] || !secretMap.contains(guess[j]))
                continue;
            
            if (secretMap[guess[j]]--) {
                cows++;
                if(secretMap[guess[j]] == 0) secretMap.erase(guess[j]);
            }
        }

        return std::to_string(bulls) + "A" + std::to_string(cows) + "B"; 
    }
};