class Solution:
    def maxOperations(self, s: str) -> int:
        ones_so_far = 0
        ans = 0
        for i in range(len(s)-1):
            if s[i] == '1':
                ones_so_far += 1
                if s[i+1] == '0':
                    ans += ones_so_far
        return ans