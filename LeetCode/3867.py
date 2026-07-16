class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        import numpy as np
        mx = np.maximum.accumulate(nums)
        pfxGcd = np.gcd(nums, mx).tolist()
        pfxGcd.sort()
        ans = 0
        for i in range(len(nums) // 2):
            ans += gcd(pfxGcd[i], pfxGcd[len(nums)-1-i])
        return ans
