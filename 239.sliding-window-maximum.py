#
# @lc app=leetcode id=239 lang=python3
#
# [239] Sliding Window Maximum
#
from typing import List
from heapq import heappush, heappop

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # return values
        heap = []
        max_vals = []

        # base case
        cur_max = (nums[0], 0)
        if k == 1:
            max_vals.append(nums[0])

        for i, val in enumerate(nums[1:], start=1):
            heappush(heap, (-val, i))
            if val > cur_max[0]:
                cur_max = (val, i)
            else: 
                # update cur_max if index expires
                while cur_max[1] <= i-k:
                    (neg_val, heap_i) = heappop(heap)
                    cur_max = (-neg_val, heap_i)
            if (i+1) >= k:
                max_vals.append(cur_max[0])
        
        return max_vals
        
# @lc code=end