from __future__ import print_function
from typing import List

# https://leetcode.com/problems/product-of-array-except-self/
# Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
# The problem can be solved in O(n) time and O(1) space complexity.
# Example 1:
# Input: nums = [1,2,3,4]
# Output: [24,12,8,6]
# Example 2:
# Input: nums = [-1,1,0,-3,3]
# Output: [0,0,9,0,0]
# Constraints:
# 2 <= nums.length <= 10^5
# -30 <= nums[i] <= 30
# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

class Solution(object):
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if nums is None or len(nums) == 0:
            return []
        
        nums_len = len(nums)
        curr_index = 0
        result = [1] * nums_len
        
        for i in range(nums_len):
            for j in range(nums_len):
                if j == curr_index:
                    continue
                result[i] = result[i] * nums[j]
            curr_index += 1
        
        return result
    
    def productExceptSelfOptimized(self, nums: List[int]) -> List[int]:
        if nums is None or len(nums) == 0:
            return []
    
        n = len(nums)
        result = [1] * n
    
        # First pass: Calculate products of all elements to the left
        prefix = 1
        for i in range(n):
            result[i] = prefix
            prefix *= nums[i]
    
        # Second pass: Calculate products of all elements to the right and combine
        suffix = 1
        for i in range(n-1, -1, -1):
            result[i] *= suffix
            suffix *= nums[i]
    
        return result
    
if __name__ == "__main__":
    soln = Solution()
    nums = [1, 2, 3, 4]
    print(soln.productExceptSelf(nums))  # Output: [24, 12, 8, 6]
    
    nums = [-1, 1, 0, -3, 3]
    print(soln.productExceptSelf(nums))  # Output: [0, 0, 9, 0, 0]
    