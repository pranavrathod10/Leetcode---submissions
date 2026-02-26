class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # intervals = sorted(intervals)
        intervals.sort(key = lambda x: x[0])
        low , high = intervals[0][0] , intervals[0][1]
        n = len(intervals)
        res = []
        if n == 1:
            return intervals
        # print(intervals)

        for i in range(1,n):
            # print(i,low,high)
            if high >= intervals[i][0]:
                low = min(low, intervals[i][0])
                high = max(intervals[i][1], high)
            else:
                res.append([low,high])
                low, high = intervals[i][0] , intervals[i][1]

            if i == n-1:
                res.append([low,high])
            

        return res
