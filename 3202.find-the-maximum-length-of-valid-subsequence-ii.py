#
# @lc app=leetcode id=3202 lang=python3
#
# [3202] Find the Maximum Length of Valid Subsequence II
#
from typing import List
from collections import Counter, defaultdict

# @lc code=start
class Solution:
    def findAlternating(self, indices_a, indices_b):
        """
        two pointer O(n) approach to counting alternating
        given two list of indices
        """
        count = 2
        l = 0
        r = 0
        is_cur_a = indices_a[0] < indices_b[0]
        while l < len(indices_a) and r < len(indices_b):
            if indices_a[l] < indices_b[r]:
                l += 1
                if not is_cur_a:
                    is_cur_a = True
                    count += 1
            else:
                r += 1
                if is_cur_a:
                    is_cur_a = False
                    count += 1
        return count

    def maximumLength(self, nums: List[int], k: int) -> int:
        parities = [num % k for num in nums]
        parity_count = Counter()
        parity_to_indices = defaultdict(list)
        for index, parity in enumerate(parities):
            parity_count.update({parity: 1})
            parity_to_indices[parity].append(index)
        counts = parity_count.most_common()
        highest_count = counts[0][1]
        for i in range(len(counts)):
            for j in range(i+1, len(counts)):
                a, count_a = counts[i]
                b, count_b = counts[j]
                if count_a+count_b>highest_count:
                    highest_count = max(
                        highest_count,
                        self.findAlternating(
                            parity_to_indices[a],
                            parity_to_indices[b]
                        )
                    )
        return highest_count
# @lc code=end

