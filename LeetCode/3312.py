class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        Q = len(queries)
        mxn = max(nums)
        q_ix = sorted([i for i in range(Q)], key=lambda k: queries[k])
        num_gcd_pairs = [0] * (mxn+1)
        num_occ = [0] * (mxn+1)
        for num in nums:
            num_occ[num] += 1
        for i in range(mxn, 0, -1):
            tot_n = sum(num_occ[i::i])
            sub = sum(num_gcd_pairs[i::i])
            num_gcd_pairs[i] = tot_n * (tot_n - 1) // 2 - sub

        ans = [0] * Q
        cur_ans = 0
        cur = 0
        for i in range(mxn+1):
            cur_ans += num_gcd_pairs[i]
            while cur < Q and cur_ans > queries[q_ix[cur]]:
                ans[q_ix[cur]] = i
                cur += 1
        
        return ans
