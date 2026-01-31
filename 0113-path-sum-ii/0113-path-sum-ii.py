# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isLeaf(self, root: ListNode) -> bool:
        if root.right == None and root.right == root.left:
            return True
        return False

    def pathSumList(self, root: Optional[TreeNode], tar: int, path: List[int], ans:List[List[int]] ):
        if root == None :
            return 
        if self.isLeaf(root):
            if tar == root.val:
                path.append(root.val)
                ans.append(path.copy())
                path.pop()
                
            return
        
        path.append(root.val)

        self.pathSumList(root.left,tar - root.val,path,ans)
        self.pathSumList(root.right,tar - root.val,path,ans)

        path.pop()

        return



    def pathSum(self, root: Optional[TreeNode], tar: int) -> List[List[int]]:
        path = []
        ans = []
        self.pathSumList(root,tar,path,ans)
        return ans