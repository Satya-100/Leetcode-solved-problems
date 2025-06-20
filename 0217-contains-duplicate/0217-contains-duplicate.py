class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        st = set()
        for i in nums:
            if i in st:
                return True
            st.add(i)
        return False