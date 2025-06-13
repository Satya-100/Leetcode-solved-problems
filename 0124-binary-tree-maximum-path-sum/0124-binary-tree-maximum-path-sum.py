# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxSum(self, root, maxi):
        if not root:
            return 0
        
        left = max(0, self.maxSum(root.left, maxi))
        right = max(0, self.maxSum(root.right, maxi))

        maxi[0] = max(maxi[0], left + right + root.val)

        return max(left, right) + root.val

    def maxPathSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        res = [float('-inf')] 
        self.maxSum(root, res)
        return res[0]