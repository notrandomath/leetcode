#
# @lc app=leetcode id=1948 lang=python3
#
# [1948] Delete Duplicate Folders in System
#
from typing import List
from collections import defaultdict

# @lc code=start
class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        child_set = defaultdict(set)
        folder_to_index = defaultdict(lambda: -1)
        for i, folder in enumerate(paths):
            folder_to_index[tuple(folder)] = i
            for j in range(1, len(folder)):
                child_set[tuple(folder[:j])].add(tuple(folder[j:]))
        to_delete = set()
        parent_set = {}
        for i, folder in enumerate(paths):
            for j in range(1, len(folder)):
                children = tuple(child_set[tuple(folder[:j])])
                i_parent = folder_to_index[tuple(folder[:j])]
                if children in parent_set and parent_set[children][1] != i_parent:
                    print('found in parent set')
                    print(i, i_parent, children)
                    print(parent_set[children])
                    print('-'*10)
                    to_delete.add(i)
                    to_delete.add(i_parent)
                    other_i, other_i_parent = parent_set[children]
                    to_delete.add(other_i)
                    to_delete.add(other_i_parent)
                else:
                    parent_set[children] = (i, i_parent)
        
        print(child_set)
        print(folder_to_index)
        print(parent_set)
                
        return [path for i, path in enumerate(paths) if i not in to_delete]

# @lc code=end

