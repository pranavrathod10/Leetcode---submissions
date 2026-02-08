# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root:
            return root
        if root == p or root == q:
            return root

        left = right = None

        if root.left:
            left = self.lowestCommonAncestor(root.left, p,q)
        if root.right:
            right = self.lowestCommonAncestor(root.right,p,q)

        if not left and not right:
            return left
        elif left == p and right == q:
            return root
        elif right == p and left == q:
            return root
        elif not left :
            return right
        elif not right:
            return left
        


        

        
        