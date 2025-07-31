#
# @lc app=leetcode id=310 lang=python3
#
# [310] Minimum Height Trees
#

from typing import List
from collections import defaultdict

# @lc code=start
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        adjacency_set = defaultdict(set)

        if len(edges) == 0:
            return [0]

        for u, v in edges:
            adjacency_set[u].add(v)
            adjacency_set[v].add(u)
        
        cur = [vertex for vertex in range(n) if len(adjacency_set[vertex]) == 1]
        passed = len(cur)
        
        while passed != n:
            next_cur = []
            for u in cur:
                for v in adjacency_set[u]:
                    adjacency_set[v].remove(u)
                    if len(adjacency_set[v]) == 1:
                        next_cur.append(v)
                        passed += 1
            cur = next_cur
        return cur


# @lc code=end

