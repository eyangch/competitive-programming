class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        ans = 1
        prev = 0
        for x in arr:
            prev = min(x, prev+1)
            ans = prev
        return ans