class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        occ = defaultdict(int)
        for num in nums:
            occ[num] += 1
        nums.sort()
        ans = max(0, occ[1] - (1 - occ[1] % 2))
        for n in nums:
            if n == 1:
                continue
            cur = 0
            cn = n
            while True:
                if occ[cn] == 1:
                    cur += 1
                    break
                elif occ[cn] >= 2:
                    cur += 1
                else:
                    break
                cn = cn * cn
                if cn > nums[-1]:
                    break
            ans = max(ans, cur * 2 - 1)
        return ans
                