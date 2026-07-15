class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        pr = 0
        occ = [0] * 3
        ans = 0
        for i in range(len(s)):
            while pr < len(s) and any(z == 0 for z in occ):
                occ[ord(s[pr]) - ord('a')] += 1
                pr += 1
            if any(z == 0 for z in occ):
                break
            ans += len(s) - pr + 1
            occ[ord(s[i]) - ord('a')] -= 1
        return ans