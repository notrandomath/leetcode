#
# @lc app=leetcode id=1695 lang=python3
#
# [1695] Maximum Erasure Value
#

from typing import List

# @lc code=start
class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        prev_sums = [nums[0] for _ in range(len(nums))]
        max_sum = nums[0]
        latest_i = -1
        to_prev_index = {nums[0]: 0}
        for i in range(1, len(nums)):
            prev_sums[i] = prev_sums[i-1]+nums[i]
            if nums[i] in to_prev_index and to_prev_index[nums[i]] >= latest_i:
                latest_i = to_prev_index[nums[i]]
            to_prev_index[nums[i]] = i
            if latest_i == -1:
                max_sum = prev_sums[i]
            elif prev_sums[i] - prev_sums[latest_i] > max_sum:
                max_sum = prev_sums[i] - prev_sums[latest_i]
        return max_sum
# @lc code=end

