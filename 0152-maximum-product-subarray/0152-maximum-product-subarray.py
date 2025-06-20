class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        res = nums[0]
        prod1 = nums[0]
        prod2 = nums[0]

        for i in range(1, n):
            temp = max({nums[i], prod1 * nums[i], prod2 * nums[i]})
            prod2 = min({nums[i], prod1 * nums[i], prod2 * nums[i]})
            prod1 = temp
            res = max(res, prod1)
        return res