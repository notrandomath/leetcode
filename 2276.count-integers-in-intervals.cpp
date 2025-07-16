/*
 * @lc app=leetcode id=2276 lang=cpp
 *
 * [2276] Count Integers in Intervals
 */

// @lc code=start
#include <vector>
using namespace std;

class CountIntervals {
public:
    vector<pair<int, int>> intervals;
    int count_val;

    CountIntervals() {
        count_val = 0;
    }
    
    void add(int left, int right) {
        pair<int, int> new_interval{left, right};

        int l = 0;
        while (l < intervals.size() && intervals[l].second+1 < new_interval.first)
            ++l;

        int r = l;
        while (r < intervals.size() && intervals[r].first-1 <= new_interval.second)
        {
            new_interval.first = min(new_interval.first, intervals[r].first);
            new_interval.second = max(new_interval.second, intervals[r].second);
            if (r > l)
                count_val += intervals[r].first-intervals[r-1].second-1;
            ++r;
        }

        if (r != l) {
            count_val += max(intervals[l].first-new_interval.first, 0);
            count_val += max(new_interval.second - intervals[r-1].second, 0);
        } else {
            count_val += new_interval.second-new_interval.first+1;
        }

        for (int i = r-1; i >= l; --i) 
            intervals.erase(intervals.begin() + i);
        intervals.insert(intervals.begin()+l, new_interval);
    }
    
    int count() {
        return count_val;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
// @lc code=end

