from __future__ import print_function
from typing import List

# 15. 3Sum
# Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
# Notice that the solution set must not contain duplicate triplets.
# Example 1:
# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
# Example 2:
# Input: nums = []
# Output: []
# Example 3:
# Input: nums = [0]
# Output: []
# Constraints:
# 0 <= nums.length <= 3000
# -10^5 <= nums[i] <= 10^5

class Solution(object):
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if nums is None or len(nums) < 3:
            return []
        
        total_nums = len(nums)
        nums_list = []
        nums.sort()
        # [-1, -1, 0, 1, 2, -4]
        
        for num in nums:
            index = nums.index(num)
            while total_nums - index != 0 and len(nums[index:]) >= 3:
                if nums[index] + nums[index + 1] + nums[index + 2] == 0:
                    _list = [nums[index], nums[index + 1], nums[index + 2]]
                    if _list not in nums_list:
                        nums_list.append(_list)
                else:
                    for i in range(index + 1, total_nums):
                        for j in range(i + 1, total_nums):
                            if nums[index] + nums[i] + nums[j] == 0:
                                _list = [nums[index], nums[i], nums[j]]
                                if _list not in nums_list:
                                    nums_list.append(_list)
                            elif nums[index] + nums[i] + nums[j] > 0:
                                break
                    
                index += 1
                    
        return nums_list
    
    def threeSumOptimized(self, nums: List[int]) -> List[List[int]]:
        # Handle base cases
        if nums is None or len(nums) < 3:
            return []
    
        # Sort the array first (O(nlogn))
        nums.sort()
        result = []
    
        # Fix the first element and use two pointers for the remaining elements
        for i in range(len(nums) - 2):
            # Skip duplicates for i
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            # Two pointers approach
            left = i + 1
            right = len(nums) - 1
        
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
            
                if current_sum == 0:
                    result.append([nums[i], nums[left], nums[right]])
                
                    # Skip duplicates for left pointer
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    # Skip duplicates for right pointer
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    
                    left += 1
                    right -= 1
                elif current_sum < 0:
                    left += 1
                else:
                    right -= 1
    
        return result
    
if __name__ == "__main__":
    soln = Solution()
    nums = [-1, 0, 1, 2, -1, -4]
    result = soln.threeSum(nums)
    print(result)
    
    nums = []
    result = soln.threeSum(nums)
    print(result)
    
    nums = [0]
    result = soln.threeSum(nums)
    print(result)
    
    nums = [-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4]
    result = soln.threeSum(nums)
    print(result)
