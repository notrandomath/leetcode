#
# @lc app=leetcode id=3201 lang=python3
#
# [3201] Find the Maximum Length of Valid Subsequence I
#
from typing import List
import copy

# @lc code=start
class Solution:
    def recursiveSol(self, i: int, sub_parity: int, prev_parity: int, nums: List[int]) -> int:
        """
        parity: 0 if even, 1 if odd (default: 0 ignored if sub_parity == -2)
        sub_parity: -2 if empty, -1 if one element, 0 if even, 1 if odd
        """
        # base case:
        if i == len(nums):
            return 0
        skip = self.recursiveSol(i+1, sub_parity, prev_parity, nums)
        if sub_parity == -2:
            return max(
                skip,
                1+self.recursiveSol(i+1, -1, nums[i]%2, nums),
            )
        if sub_parity == -1:
            return max(
                skip,
                1+self.recursiveSol(i+1, (prev_parity+nums[i])%2, nums[i]%2, nums),
            )
        if (prev_parity + nums[i]) % 2 != sub_parity:
            return skip
        return max(
            skip,
            1+self.recursiveSol(i+1, sub_parity, nums[i]%2, nums)
        )

    def pretty_print(self, dp_sums: List[List[List[int]]]):
        print(['sub -2 parity 0', 'sub -1 parity 0', 'sub 0 parity 0', 'sub 1 parity 0', 'sub -2 parity 1', 'sub -1 parity 1', 'sub 0 parity 1', 'sub 1 parity 1'])
        for i in range(len(dp_sums)):
            print([dp_sums[i][j % 4][j / 4] for j in range(8)])

    def maximumLength(self, nums: List[int]) -> int:
        dp_sums = [
            [
                [
                    0 for _ in range(2)
                ] for _ in range(-2, 2)
            ] for _ in range(len(nums)+1)
        ]
        for i in reversed(range(len(nums))):
            for sub_parity in range(-2, 2):
                for prev_parity in range(2):
                    skip = dp_sums[i+1][sub_parity][prev_parity]
                    if sub_parity == -2:
                        dp_sums[i][sub_parity][prev_parity] = max(
                            skip,
                            1+dp_sums[i+1][-1][nums[i]%2]
                        )
                    elif sub_parity == -1:
                        dp_sums[i][sub_parity][prev_parity] = max(
                            skip,
                            1+dp_sums[i+1][(prev_parity+nums[i])%2][nums[i]%2]
                        )
                    elif (prev_parity + nums[i]) % 2 != sub_parity:
                        dp_sums[i][sub_parity][prev_parity] = skip
                    else:
                        dp_sums[i][sub_parity][prev_parity] = max(
                            skip,
                            1+dp_sums[i+1][sub_parity][nums[i]%2]
                        )
        # self.pretty_print(dp_sums)
        return dp_sums[0][-2][0]

# @lc code=end

