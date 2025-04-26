from __future__ import print_function
from typing import List

# 39. Combination Sum
# https://leetcode.com/problems/combination-sum/
# Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
# You may return the combinations in any order.

class Solution(object):
    def combinationSum(self, candidates, target):
        result = []

        def search(path, total):
            if total == target:
                result.append(path)
                return
            if total > target:
                return

            for i in range(len(candidates)):
                # Allow repeated use by passing same i
                new_path = path + [candidates[i]]
                search(new_path, total + candidates[i])

        # Sort to help with optimization (optional here)
        candidates.sort()
        search([], 0)
        return [combo for combo in result if sorted(combo) not in [sorted(r) for r in result[:result.index(combo)]]]
    
if __name__ == "__main__":
    s = Solution()
    candidates = [ 2, 3, 6, 7 ]
    target = 7
    result = s.combinationSum(candidates, target)
    print("result = ", result)  # [[2, 2, 3], [7]]
    
    candidates = [ 2, 3, 5 ]
    target = 8
    result = s.combinationSum(candidates, target)
    print("result = ", result)  # [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
