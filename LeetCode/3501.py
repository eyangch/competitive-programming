class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        sn = [int(c) for c in s]
        pfx = [0] * (n+1)
        for i in range(n):
            pfx[i+1] = pfx[i] + sn[i]
        
        next_zb = [-1] * (n+1)
        # stores the next ...10... boundary
        for i in range(n-1, 0, -1):
            if sn[i] == 0 and sn[i-1] == 1:
                next_zb[i] = i
            else:
                next_zb[i] = next_zb[i+1]
        next_zb[0] = next_zb[1]

        prev_zb = [-1] * n
        # stores the previous ...01... boundary
        for i in range(0, n-1):
            if sn[i] == 0 and sn[i+1] == 1:
                prev_zb[i] = i
            elif i > 0:
                prev_zb[i] = prev_zb[i-1]
        if n > 1:
            prev_zb[n-1] = prev_zb[n-2]

        ctz_after = [0] * n
        if sn[n-1] == 0:
            ctz_after[n-1] = 1
        for i in range(n-2, -1, -1):
            if sn[i] == 0:
                ctz_after[i] = ctz_after[i+1] + 1
            else:
                ctz_after[i] = 0
        
        ctz_before = [0] * n
        if sn[0] == 0:
            ctz_before[i] = 1
        for i in range(1, n):
            if sn[i] == 0:
                ctz_before[i] = ctz_before[i-1] + 1
            else:
                ctz_before[i] = 0

        # query next_zb[l]...prev_zb[r]
        st = [[0] * n for _ in range(18)]

        segs = []
        cur_z = 0
        for j in range(n):
            if sn[j] == 0:
                cur_z += 1
            else:
                if cur_z > 0:
                    segs.append((j - cur_z, j-1))
                cur_z = 0
        if cur_z > 0:
            segs.append((n - cur_z, n-1))
        
        for i in range(len(segs)-1):
            val = segs[i][1] - segs[i][0] + segs[i+1][1] - segs[i+1][0] + 2
            st[0][segs[i][0]] = max(st[0][segs[i][0]], val)

        for i in range(1, 18):
            for j in range(n):
                if j + (1 << (i-1)) >= n:
                    break
                st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i-1))])
        
        def get_mx(l, r, st):
            if l > r:
                return 0
            lg2 = (r-l+1).bit_length() - 1
            # print(l, r, r - (1 << lg2) + 1, lg2)
            assert r - (1 << lg2) + 1 >= l
            return max(st[lg2][l], st[lg2][r - (1 << lg2) + 1])

        ans = []
        for l, r in queries:
            r_add = 0
            l_add = 0
            base = pfx[r+1] - pfx[l]
            add = pfx[n] - base

            if sn[r] == 1:
                r = prev_zb[r]
            # print(f"{prev_zb=}")
            if r <= 0:
                ans.append(base + add)
                continue
            # must have sn[r] == 0
            r_add += ctz_before[r]
            r_pre = prev_zb[r-1]
            if r_pre < l:
                ans.append(base + add)
                continue
            r_pre2 = r_pre - ctz_before[r_pre] + 1
            r_pre2 = max(r_pre2, l)
            r_add += r_pre - r_pre2 + 1

            if l == r_pre2:
                # print(f"{l=}, {r=}, {base=}, {r_add=}, {add=}")
                # print(f"{r_pre=}, {r_pre2=}")
                ans.append(base + r_add + add)
                continue
            
            if sn[l] == 0:
                l_add = ctz_after[l] + ctz_after[next_zb[l+1]]
                l = next_zb[l]
            
            # print(f"{l=}, {r_pre2=}")
            # print(f"{base=}, {l_add=}, {r_add=}, {get_mx(l, r_pre2-1, st)=}")
            ans.append(base + add + max(l_add, r_add, get_mx(l, r_pre2-1, st)))

        return ans

