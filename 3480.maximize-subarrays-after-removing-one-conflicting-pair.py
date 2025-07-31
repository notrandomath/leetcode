#
# @lc app=leetcode id=3480 lang=python3
#
# [3480] Maximize Subarrays After Removing One Conflicting Pair
#

from typing import List

# 1 2
# 2 3
# 3 4
# 1 2 3
# 2 3 4
# 1 2 3 4

# 1 2
# 2 3
# 3 4
# 4 5
# 1 2 3
# 2 3 4
# 3 4 5
# 1 2 3 4
# 2 3 4 5
# 1 2 3 4 5

# @lc code=start
class Solution:
    def maxSubarrays(self, n: int, conflictingPairs: List[List[int]]) -> int:
        total = n * (n+1) // 2
        m = n // 2 
        most_freq = m*(m+1) if (n-1) % 2 == 0 else m*m
        
# @lc code=end

