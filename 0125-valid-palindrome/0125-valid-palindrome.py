class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        result = ""
        for i in range(len(s)):
            if s[i].isalnum():
                result += s[i].lower()
        original = result
        result = list(result)
        l = 0
        r = len(result) - 1
        while l < r:
            result[l], result[r] = result[r], result[l]
            l += 1
            r -= 1
        reversed_str = "".join(result)
        return original == reversed_str
        