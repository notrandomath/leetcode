#
# @lc app=leetcode id=239 lang=python3
#
# [239] Sliding Window Maximum
#
from typing import List
from collections import deque

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # return values
        dq = deque()
        max_vals = []

        for i, val in enumerate(nums):
            while len(dq) != 0 and val > dq[-1]:
                dq.pop()
            dq.append(val)
            if i >= k and nums[i-k] == dq[0]:
                dq.popleft()
            if (i+1) >= k:
                max_vals.append(dq[0])
    
        return max_vals
        
# @lc code=end