#
# @lc app=leetcode id=2410 lang=python3
#
# [2410] Maximum Matching of Players With Trainers
#
from typing import List

# @lc code=start
class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()

        l = 0
        r = 0

        while l < len(players) and r < len(trainers):
            if players[l] <= trainers[r]:
                l += 1
                r += 1
            else:
                r += 1

        return l
        
# @lc code=end

