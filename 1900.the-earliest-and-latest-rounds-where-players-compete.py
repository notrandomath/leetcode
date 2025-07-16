#
# @lc app=leetcode id=1900 lang=python3
#
# [1900] The Earliest and Latest Rounds Where Players Compete
#
from typing import List
from collections import namedtuple
from itertools import combinations

# @lc code=start
class Solution:
    def recursive_sol(self, 
        firstPlayer: int, 
        secondPlayer: int, 
        l: int,
        r: int,
        n: int,
        timesteps: int,
        return_max: bool
    ) -> int:
        if timesteps == 0:
            return self.recursive_sol(firstPlayer, secondPlayer, 0, n-1, n, n//2, return_max)+1
        if l == firstPlayer and r == secondPlayer or l == secondPlayer and r == firstPlayer:
            return 1
        else:
            l_sol = lambda: self.recursive_sol(
                firstPlayer-1 if firstPlayer > l else firstPlayer, 
                secondPlayer-1 if secondPlayer > l else secondPlayer, 
                l, r-2, n-1, timesteps-1, return_max)
            r_sol = lambda: self.recursive_sol(
                firstPlayer-1 if firstPlayer > r else firstPlayer, 
                secondPlayer-1 if secondPlayer > r else secondPlayer, 
                l+1, r-1, n-1, timesteps-1, return_max)
            if l == firstPlayer or l == secondPlayer:
                return r_sol()
            if r == firstPlayer or r == secondPlayer:
                return l_sol()
            if return_max:
                return max(l_sol(), r_sol())
            return min(l_sol(), r_sol())

    def earliestAndLatest(self, n: int, firstPlayer: int, secondPlayer: int) -> List[int]:
        turnTuple = namedtuple('turnTuple', ['min', 'max'])
        firstPlayer -= 1
        secondPlayer -= 1

        players_dp = [
            [
                [
                    [
                        [
                            [
                                None for secondPlayer in range(n_i)
                            ] for firstPlayer in range(n_i)
                        ] for r in range(n_i)
                    ] for l in range(n_i)
                ] for timestep in range(n_i//2)
            ] for n_i in range(2, n)
        ]

        start_combos = []

        for n_i in range(2, n):
            for timestep in range(n_i//2):
                for l, r in combinations(range(n_i), 2):
                    players_dp[n_i-2][timestep][l][r][l][r] = turnTuple(1, 1)
                    players_dp[n_i-2][timestep][l][r][r][l] = turnTuple(1, 1)
                    start_combos.append((l, r))

        for n_i in range(2, n):
            for timestep in range(n_i//2):
                for start_l, start_r in start_combos:
                    n_i2 = n_i
                    timestep_i2 = timestep
                    while n_i2 < n and timestep_i2 < n:
                        

        return [
            self.recursive_sol(firstPlayer, secondPlayer, 0, n-1, n, n//2, False),
            self.recursive_sol(firstPlayer, secondPlayer, 0, n-1, n, n//2, True)
        ]

# @lc code=end

