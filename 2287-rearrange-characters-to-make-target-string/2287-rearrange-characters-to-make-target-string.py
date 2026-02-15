class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        maps = {}
        mapt = {}
        for ch in s:
            maps[ch] = maps.get(ch,0)+1

        for ch in target:
            mapt[ch] = mapt.get(ch,0)+1

        ans = float('inf')

        for ch in target:
            ans = min(ans, maps.get(ch,0)//mapt.get(ch,0))

        return ans
