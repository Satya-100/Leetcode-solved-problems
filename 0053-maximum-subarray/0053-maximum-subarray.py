class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = float("-inf")
        temp = 0
        for i in nums:
            temp += i
            res = max(res, temp)
            if temp < 0:
                temp = 0
        return res