#
# @lc app=leetcode id=2163 lang=python3
#
# [2163] Minimum Difference in Sums After Removal of Elements
#
from typing import List

# @lc code=start
DEBUG = True

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums)//3
        i_nums = list(enumerate(nums[:2*n]))
        i_nums.sort(key=lambda x: x[1])
        first_sum = sum([val for _, val in i_nums[:n]])
        if DEBUG:
            print('Left:')
            print(i_nums)
            print([val for _, val in i_nums[:n]])
            print(first_sum)
            print('-'*10)
        new_nums = [val for i, val in i_nums[n:] if i >= n] + nums[2*n:]
        new_nums.sort(reverse=True)
        second_sum = sum(new_nums[:n])
        if DEBUG:
            print('Right:')
            print(new_nums)
            print(new_nums[:n])
            print(second_sum)
        return first_sum-second_sum

# @lc code=end

