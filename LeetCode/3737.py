class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        # sweep through B, to check [a, B] has > (B - a + 1) / 2
        # [a, B] > B / 2 - a / 2 + 1 / 2 => [0, B] - [0, a-1] > B / 2 - a / 2 + 1 / 2
        # => [0, B] - B / 2 > [0, a-1] - a / 2 + 1 / 2
        # => 2 * [0, B] - B > 2 * [0, a-1] - a + 1
        n = len(nums)
        pfx = [0] * n
        for i in range(1, n):
            pfx[i] = pfx[i-1] + int(nums[i-1] == target)
        for i in range(n):
            pfx[i] = pfx[i] * 2 - i + 1
        
        cur_cnt = 0
        cur_thresh = 1
        cnt = defaultdict(int)

        ans = 0

        print(pfx)

        # each time, 2 * [0, B] - B changes by: {-1, 1}
        for i in range(n):
            cnt[pfx[i]] += 1
            if pfx[i] < cur_thresh:
                cur_cnt += 1
            # if nums[i] == target, change by +1, else change by -1
            if nums[i] == target:
                cur_cnt += cnt[cur_thresh]
                cur_thresh += 1
            else:
                cur_thresh -= 1
                cur_cnt -= cnt[cur_thresh]
            ans += cur_cnt
        
        return ans

