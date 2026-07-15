class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [[0] * 2 for _ in range(len(nums))]
        dp[0][1] = nums[0]
        for i in range(1, len(nums)):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1])
            dp[i][1] = dp[i-1][0] + nums[i]
        return max(dp[len(nums)-1])