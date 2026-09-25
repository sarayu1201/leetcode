class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        freq={}
        for num in nums:
            freq[num]=freq.get(num,0)+1
        for num in nums:
            if freq[num]>len(nums)//2:
                return num
             