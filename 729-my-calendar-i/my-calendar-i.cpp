class MyCalendar {
    std::set<std::pair<int, int>> intervals;

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto loBound = intervals.lower_bound({start, end});

        if (loBound != intervals.end() && end > loBound->first)
            return false;

        if (loBound != intervals.begin() && start < (--loBound)->second)
            return false;

        intervals.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */