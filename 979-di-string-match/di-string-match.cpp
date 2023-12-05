class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0;
        int high = s.size();

        std::vector<int> perm;
        for (const char &ch : s) {
            if (ch == 'I')
                perm.push_back(low++);
            else
                perm.push_back(high--);
        }

        perm.push_back(low);

        return perm;
    }
};