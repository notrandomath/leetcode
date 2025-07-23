#
# @lc app=leetcode id=1233 lang=python3
#
# [1233] Remove Sub-Folders from the Filesystem
#
from typing import List

# @lc code=start
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        marked_set = set()
        for indiv in folder:
            marked_set.add(tuple(indiv.split('/')[1:]))
        new_folders = []
        for indiv in folder:
            indiv_split = indiv.split('/')[1:]
            in_set = False
            for i in range(1, len(indiv_split)):
                if tuple(indiv_split[:-i]) in marked_set:
                    in_set = True
                    break
            if in_set:
                continue
            new_folders.append(indiv)
        return new_folders
# @lc code=end

