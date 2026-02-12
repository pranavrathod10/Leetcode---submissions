# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        left = right = 0
        if root.left:
            left = 1 + self.solve(root.left)

        if root.right:
            right = 1 + self.solve(root.right)

        self.ans = max(self.ans , left + right)

        return max(left,right)
        
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        self.solve(root)
        return self.ans