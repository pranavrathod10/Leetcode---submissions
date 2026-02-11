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
        
        if not root.left and not root.right:
            return root.val
        
        left  = right = -float('inf')
        # self.ans = max(self.ans , root.val)
        if root.left:
            left = self.solve(root.left)
            # print(left)
        if root.right:
            right = self.solve(root.right)
            # print(right)

        self.ans = max(self.ans , left , right, root.val, left+root.val, root.val+right, root.val+left+right)

        return max(root.val , left+root.val, root.val+right)

        
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans = -float('inf')
        if not root:
            return 0
        if not root.left and not root.right:
            return root.val
        self.solve(root)
        return self.ans