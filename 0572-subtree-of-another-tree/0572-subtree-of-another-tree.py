# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, rootA, rootB):
        if not rootA and not rootB:
            return True
        if (not rootA or not rootB) or rootA.val != rootB.val:
            return False
        return self.isSameTree(rootA.left, rootB.left) and self.isSameTree(rootA.right, rootB.right)

    def isSubtree(self, root, subRoot):
        """
        :type root: Optional[TreeNode]
        :type subRoot: Optional[TreeNode]
        :rtype: bool
        """
        if not root:
            return False
        if(self.isSameTree(root, subRoot)):
            return True
        
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)