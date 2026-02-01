# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def func(self, root: Optional[TreeNode]) -> int:
        # res = 0
        
        if root.left == root.right == None:
            return 0
        resLeft = resRight = 0
        if root.left:
            resLeft += 1 + self.func(root.left)
        if root.right:
            resRight += 1 + self.func(root.right)

        self.ans = max(self.ans, resLeft + resRight)

        return max(resLeft,resRight)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        self.ans  = 0
        self.func(root)

        return self.ans