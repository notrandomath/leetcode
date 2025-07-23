#
# @lc app=leetcode id=1717 lang=python3
#
# [1717] Maximum Score From Removing Substrings
#

# @lc code=start
class Solution:
    # def maximumGainRecursive(self, i: int, s: str, x: int, y: int) -> int:
    #     # base case
    #     if i >= len(s)-1:
    #         return 0
    #     if i == len(s)-2:
    #         if s[i:i+2] == 'ab':
    #             return x
    #         if s[i:i+2] == 'ba':
    #             return y
    #         return 0
        
    #     skip = self.maximumGainRecursive(i+1, s, x, y)
    #     delete_i = i-1 if i != 0 else i        

    #     if s[i:i+2] == 'ab':
    #         return max(
    #             self.maximumGainRecursive(delete_i, s[:i]+s[i+2:], x, y)+x,
    #             skip
    #         )
    #     elif s[i:i+2] == 'ba':
    #         return max(
    #             self.maximumGainRecursive(delete_i, s[:i]+s[i+2:], x, y)+y,
    #             skip
    #         )
    #     else:
    #         return skip

    def maximumGain(self, s: str, x: int, y: int) -> int:
        # return self.maximumGainRecursive(0, s, x, y)

        target = 'ab' if x > y else 'ba'
        non_target = 'ba' if x > y else 'ab'

        score = 0

        i = 0
        while i < len(s)-1:
            if s[i:i+2] == target:
                s = s[:i] + s[i+2:] if i != len(s)-2 else s[:i]
                if i != 0:
                    i -= 1
                score += max(x, y)
            else:
                i += 1
        
        i = 0
        while i < len(s)-1:
            if s[i:i+2] == non_target:
                s = s[:i] + s[i+2:] if i != len(s)-2 else s[:i]
                if i != 0:
                    i -= 1
                score += min(x, y)
            else:
                i += 1
        
        return score
        
# aaaa
# aaab
# aaba
# aabb
# abaa
# abab
# abba
# abbb
# baaa
# baab
# baba
# babb
# bbaa
# bbab
# bbba
# bbbb

# @lc code=end