class Solution(object):
    def majorityElement(self, nums: list) -> int:
        """
        :type nums: List[int]
        :rtype: int
        """
        majority_index = len(nums) / 2
        nums_dict: dict = {}
        for _num in nums:
            if _num in nums_dict.keys():
                nums_dict[_num] += 1
            else:
                nums_dict[_num] = 1
                
        max_key = max(nums_dict, key=lambda k: nums_dict[k] > majority_index)
        return max_key
    
if __name__ == "__main__":
    soln = Solution()
    
    nums = [3,2,3]
    num = soln.majorityElement(nums)
    print(f"majority num : {num}")
    
    nums = [2,2,1,1,1,2,2]
    num = soln.majorityElement(nums)
    print(f"majority num : {num}")
