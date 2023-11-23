class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        std::string encoded;

        for (const auto &str : strs)
            encoded += std::to_string(str.size()) + "[" + str + "]";

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        std::vector<std::string> strs;

        int index = 0;
        while (index < s.size()) {
            std::string length;
            while (s[index] != '[')
                length.push_back(s[index++]);

            int strLength = std::stoi(length);
            std::string currentString = s.substr(index + 1, strLength);
            strs.push_back(currentString);

            index += strLength + 2;
        }

        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));