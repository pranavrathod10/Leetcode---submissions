class Solution:
    def minMoves(self, nums: List[int]) -> int:
        # def minMoves(nums):
        return sum(nums) - len(nums) * min(nums)