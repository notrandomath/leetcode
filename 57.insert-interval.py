#
# @lc app=leetcode id=57 lang=python3
#
# [57] Insert Interval
#

from typing import List

# @lc code=start
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        l = 0
        while l < len(intervals) and newInterval[0] > intervals[l][1]:
            l += 1
        r = l
        while r < len(intervals) and newInterval[1] >= intervals[r][0]:
            newInterval = [
                min(newInterval[0], intervals[r][0]),
                max(newInterval[1], intervals[r][1])
            ]
            r += 1
        return intervals[:l] + [newInterval] + intervals[r:]


            
# @lc code=end

