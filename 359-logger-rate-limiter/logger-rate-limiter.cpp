class Logger {
    std::unordered_map<std::string, int> logStamp;

public:
    Logger() {
        logStamp = std::unordered_map<std::string, int>();     
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (logStamp.contains(message) && timestamp - logStamp[message] < 10)
            return false;

        logStamp[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */