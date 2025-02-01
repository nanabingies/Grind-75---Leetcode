class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        outer_list = set()
        for _num in nums:
            if _num in outer_list:
                return True
            outer_list.add(_num)
        return False
    
soln = Solution()
nums = [1,2,3,1]
found = soln.containsDuplicate(nums)
print(f"found : {found}")

nums = [1,2,3,4]
found = soln.containsDuplicate(nums)
print(f"found : {found}")

nums = [1,1,1,3,3,4,3,2,4,2]
found = soln.containsDuplicate(nums)
print(f"found : {found}")
