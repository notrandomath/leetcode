#
# @lc app=leetcode id=56 lang=python3
#
# [56] Merge Intervals
#
from typing import List

# @lc code=start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sorted_intervals = sorted(intervals, key= lambda x: x[0])
        if len(sorted_intervals) == 1:
            return sorted_intervals
        merged_intervals = []
        i = 0
        while i < len(sorted_intervals)-1:
            if sorted_intervals[i][1] < sorted_intervals[i+1][0]:
                merged_intervals.append(sorted_intervals[i])
            else:
                new_interval = [sorted_intervals[i][0], sorted_intervals[i][1]]
                while i < len(sorted_intervals)-1 and sorted_intervals[i+1][0] <= new_interval[1]:
                    new_interval[1] = max(sorted_intervals[i+1][1], new_interval[1])
                    i += 1
                merged_intervals.append(new_interval)
            if i == len(sorted_intervals)-2:
                merged_intervals.append(sorted_intervals[-1])
            i += 1
        return merged_intervals

# @lc code=end

