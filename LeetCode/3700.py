class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 1000000007
        @cache
        def p2_nways(lv, rv, linc, gap):
            # print(f"prelim p2_nways({lv}, {rv}, {linc}, {rinc}, {gap})")
            # print(f"p2_nways({lv}, {rv}, {linc}, {rinc}, {gap})")
            if gap == 2:
                if linc and rv < lv:
                    return 1
                if not linc and rv > lv:
                    return 1
                return 0
            
            if gap == 1:
                if lv == rv:
                    return 1
                return 0
            
            res = 0
            for mid_v in range(l, r+1):
                if (gap + 1) // 2 > 2:
                    way_a = (
                        p2_nways(lv, mid_v, linc, (gap + 1) // 2)
                        * p2_nways(mid_v, rv, linc, (gap + 1) // 2)
                    ) % MOD
                else:
                    way_a = (
                        p2_nways(lv, mid_v, linc, (gap + 1) // 2)
                        * p2_nways(mid_v, rv, not linc, (gap + 1) // 2)
                    ) % MOD
                res = (res + way_a) % MOD
            
            return res
        
        p2p1 = [2**i+1 for i in range(31, -1, -1)]

        @cache
        def compute(n, lv, linc):
            # print(f"compute({n}, {lv}, {linc})")
            if n <= 1:
                return 1
            for z in p2p1:
                if z <= n:
                    break
            res = 0
            for rv in range(l, r+1):
                # print(z, p2_nways(lv, rv, linc, not linc, z))
                if z > 2:
                    res = (
                        res
                        + (
                            p2_nways(lv, rv, linc, z)
                            * compute(n - z + 1, rv, linc)
                        ) % MOD
                    ) % MOD
                else:
                    res = (
                        res
                        + (
                            p2_nways(lv, rv, linc, z)
                            * compute(n - z + 1, rv, not linc)
                        ) % MOD
                    ) % MOD

            # print(f"compute({n}, {lv}, {linc}) = {res}")

            return res

        ans = 0
        for i in range(l, r+1):
            ans = (ans + compute(n, i, False) + compute(n, i, True)) % MOD

        return ans        
            

                