class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums) - 1
        res = float("inf")

        while l <= r:
            mid = (l + r) // 2
            if nums[l] <= nums[r]:
                res = min(res, nums[l])
                break
            if nums[l] <= nums[mid]:
                res = min(res, nums[l])
                l = mid + 1
            elif nums[mid] <= nums[r]:
                res = min(res, nums[mid])
                r = mid - 1
        
        return res