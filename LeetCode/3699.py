import numpy as np

class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 1000000007
        dp = [[[1, 1] for _ in range(r - l + 1)] for __ in range(2)]
        dp = np.ones((2, 2, r-l+1), dtype=np.int64)
        for k in range(n):
            old_dp = dp[k % 2]
            new_dp = dp[1 - k % 2]
            new_dp[0][:-1] = old_dp[1][1:]
            new_dp[1][1:] = old_dp[0][:-1]
            new_dp[1][0] = 0
            new_dp[0][-1] = 0
            new_dp[0] = np.cumsum(new_dp[0]) % MOD
            new_dp[1] = np.cumsum(new_dp[1][::-1])[::-1] % MOD
        
        ans = new_dp[0][r-l] + new_dp[1][0]
        
        return (ans % MOD).item()
                   

                