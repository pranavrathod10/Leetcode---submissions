class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        map = {}
        n = len(s)
        if n == 0:
            return 0

        ans = 1
        left = 0
        # if s == " ":
        #     return 1
        for i in range(n):
            # print(i," ---- ")
            if s[i] not in map:
                map[s[i]] = i
                ans = max(ans, i - left+1)
            else:
                # ans = max(ans, i - left+1)
                # print(ans)
                # low = map[s[i]]
                while s[i] in map:
                    map.pop(s[left])
                    left+=1

                # map[s[i]] = i 

                map[s[i]] = i

        return ans