class Solution {
    int RADIX_1 = 26;
    long MOD1 = 2038074743;

    int RADIX_2 = 27;
    long MOD2 = 3121238921;

    std::pair<long, long> hashing(std::string str, int m) {
        long hash1 = 0;
        long hash2 = 0;

        for (int i = 0; i < m; i++) {
            int ch = str[i] - 'a';
            hash1 = ((hash1 * RADIX_1) % MOD1 + ch % MOD1) % MOD1;
            hash2 = ((hash2 * RADIX_2) % MOD2 + ch % MOD2) % MOD2;
        }
        
        return {hash1, hash2};
    }

public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size())
            return -1;

        int m = needle.size();
        auto haystackHash = std::pair<long, long>{};
        auto needleHash = hashing(needle, m);

        long MAX_POWER1 = 1;
        long MAX_POWER2 = 1;
        for (int i = 0; i < m; i++) {
            MAX_POWER1 = (MAX_POWER1 * RADIX_1) % MOD1;
            MAX_POWER2 = (MAX_POWER2 * RADIX_2) % MOD2;
        }

        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            if (i == 0) {
                haystackHash = hashing(haystack, m);
            } else {
                int inChar = haystack[i + m - 1] - 'a';
                int outChar = haystack[i - 1] - 'a';

                haystackHash.first = ((haystackHash.first * RADIX_1) % MOD1 - (outChar * MAX_POWER1) % MOD1 + inChar % MOD1 + MOD1) % MOD1;
                haystackHash.second = ((haystackHash.second * RADIX_2) % MOD2 - (outChar * MAX_POWER2) % MOD2 + inChar % MOD2 + MOD2) % MOD2;
            }

            if (haystackHash == needleHash)
                return i;
        }

        return -1;
    }
};