class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        nums.sort()
        duplicate=nums[0]
        for i in range(1,len(nums)):
            if duplicate==nums[i]:
                return True
            else:
               duplicate=nums[i]
        return False        