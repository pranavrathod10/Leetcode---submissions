class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        x = 1
        res.append([])
        n = len(nums)
        for i in range(1,2**(n)):
            subset = []
            # print(i)
            for j in range(n):
                if (i >> j) & 1 == 1:
                    subset.append(nums[j])
            
            res.append(subset)
            # x+=1

        return res