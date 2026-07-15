class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        dif = [0] + [target[i] - nums[i] for i in range(len(nums))] + [0]
        ddif = [abs(dif[i+1] - dif[i]) for i in range(len(dif)-1)]
        return sum(ddif)//2
        