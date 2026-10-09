class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        for num in range(len(nums)+1):
            if num not in nums:
                return num
        return -1