class Solution:
    def findDifference(self, nums1: list[int], nums2: list[int]) -> list[list[int]]:
        set1=set(nums1)
        set2=set(nums2)
        ans1=set1-set2
        ans2=set2-set1
        return [list(ans1),list(ans2)]
        
        