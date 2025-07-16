#
# @lc app=leetcode id=2276 lang=python3
#
# [2276] Count Integers in Intervals
#

# @lc code=start
class CountIntervals:

    def __init__(self):
        self.intervals = []
        self.count_val = 0

    def add(self, left: int, right: int) -> None:
        new_interval = [left, right]

        l = 0
        while l < len(self.intervals) and self.intervals[l][1]+1 < new_interval[0]:
            l += 1

        r = l
        while r < len(self.intervals) and self.intervals[r][0]-1 <= new_interval[1]:
            new_interval[0] = min(new_interval[0], self.intervals[r][0])
            new_interval[1] = max(new_interval[1], self.intervals[r][1])
            if r > l:
                self.count_val += self.intervals[r][0]-self.intervals[r-1][1]-1
            r += 1
            
        if r != l:
            self.count_val += max(self.intervals[l][0] - new_interval[0], 0)
            self.count_val += max(new_interval[1] - self.intervals[r-1][1], 0)
        else:
            self.count_val += new_interval[1]-new_interval[0]+1
        
        for i in reversed(range(l, r)):
            self.intervals.pop(i)
        self.intervals.insert(l, new_interval)

    def count(self) -> int:
        return self.count_val


# Your CountIntervals object will be instantiated and called as such:
# obj = CountIntervals()
# obj.add(left,right)
# param_2 = obj.count()
# @lc code=end

