#
# @lc app=leetcode id=3136 lang=python3
#
# [3136] Valid Word
#
import re
# @lc code=start
class Solution:
    def isValid(self, word: str) -> bool:
        return re.match(r'(?=.*[aeiou])(?=.*(?![aeiou])[a-z])^[a-z0-9]{3,}$', 
                        word, flags=re.IGNORECASE) is not None
# @lc code=end

