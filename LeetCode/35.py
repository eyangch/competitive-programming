class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        lo, hi, mid, res = 0, len(nums)-1, 0, len(nums)
        while lo <= hi:
            mid = (lo + hi) // 2
            if nums[mid] >= target:
                res = mid
                hi = mid-1
            else:
                lo = mid+1
        return res