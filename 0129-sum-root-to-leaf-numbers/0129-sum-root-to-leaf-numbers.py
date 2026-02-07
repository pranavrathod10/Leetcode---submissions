# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: TreeNode, path: List[int]):
        if not root.left and not root.right:
            # path+= str(root.val)
            path.append(root.val)
            x = int("".join(map(str,path)))
            print(x)
            self.ans += x
            path.pop()
            return

        if root.left:
            path.append(root.val)
            self.solve(root.left,path)
            path.pop()

        if root.right:
            path.append(root.val)
            self.solve(root.right,path)
            path.pop()

        return

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        path = []
        self.solve(root,path)
        return self.ans