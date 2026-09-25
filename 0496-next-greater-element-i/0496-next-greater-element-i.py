class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        stack=[]
        result={}
        for i in range(len(nums2)):
            while stack and nums2[i]>nums2[stack[-1]]:
                index=stack.pop()
                result[nums2[index]]=nums2[i]
            stack.append(i)
        answer=[]
        for n in nums1:
            answer.append(result.get(n,-1))
        return answer
        