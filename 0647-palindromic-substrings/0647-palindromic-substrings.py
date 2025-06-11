class Solution(object):
    def countPalindrome(self, s, l, r):
        res = 0
        while l>=0 and r<len(s) and s[l]==s[r]:
                res += 1
                l -= 1
                r += 1
        return res

    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0

        for i in range(len(s)):
            res += self.countPalindrome(s, i, i)
            res += self.countPalindrome(s, i, i+1)
        
        return res