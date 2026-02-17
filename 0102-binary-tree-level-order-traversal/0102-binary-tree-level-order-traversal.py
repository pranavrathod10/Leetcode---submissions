# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        q = deque()
        if not root:
            return ans

        q.append(root)
        ans.append([root.val])

        while len(q) > 0:
            n = len(q)
            level_vals = []
            while n:
                curr = q.popleft()
                # q.append(curr)
                if curr.left:
                    q.append(curr.left)
                    level_vals.append(curr.left.val)

                if curr.right:
                    q.append(curr.right)
                    level_vals.append(curr.right.val)

                n-=1
                
            if level_vals:
                ans.append(level_vals)

        return ans

