# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: Optional[TreeNode]) -> int:
        if not root.left and not root.right:
            x = root.val
            root.val = 0
            # self.ans +x
            return x
        left = right = 0
        if root.left:
            left = self.solve(root.left)
        
        if root.right:
            right = self.solve(root.right)

        tilt = abs(left - right)
        self.ans += tilt
        actual_val = root.val
        root.val = tilt
        return left+right+actual_val




    def findTilt(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        if not root:
            return 0
        self.solve(root)
        return self.ans