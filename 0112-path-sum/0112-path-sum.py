# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isLeaf(self, root: ListNode) -> bool:
        if root.left == None and root.right == None:
            return True
        return False
        
    def hasPathSum(self, root: Optional[TreeNode], tar: int) -> bool:
        if root == None:
            return False
        if self.isLeaf(root) and tar != root.val:
            return False
        if self.isLeaf(root) and tar == root.val:
            return True

        
        return self.hasPathSum(root.left,tar - root.val) or self.hasPathSum(root.right,tar - root.val)
