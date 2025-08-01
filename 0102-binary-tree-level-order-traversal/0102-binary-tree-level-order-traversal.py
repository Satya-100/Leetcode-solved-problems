# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        res = []
        q = deque()
        q.append(root)

        while q:
            length = len(q)
            temp = []
            for i in range(length):
                node = q.popleft()
                if node:
                    temp.append(node.val)

                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
            if temp:
                res.append(temp)
        return res