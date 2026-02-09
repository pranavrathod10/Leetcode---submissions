# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: TreeNode) -> List[int]:
        if not root:
            return [0,0]
        
        left = self.solve(root.left)
        right = self.solve(root.right)

        res = [0,0]

        res[0] = max(left[0], left[1]) + max(right[0],right[1])
        res[1] = root.val + left[0] + right[0]

        return res


    def rob(self, root: Optional[TreeNode]) -> int:
        arr = self.solve(root)
        return max(arr[0],arr[1])