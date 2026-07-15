class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        restrictions = [[1, 0]] + sorted(restrictions, key=lambda x: x[0]) + [[n, 1e18]]
        for i in range(1, len(restrictions)):
            x, h = restrictions[i]
            px, ph = restrictions[i-1]
            mxh_before = (x - px) + ph
            restrictions[i][1] = min(h, mxh_before)
        for i in range(len(restrictions)-2, -1, -1):
            x, h = restrictions[i]
            px, ph = restrictions[i+1]
            mxh_before = (px - x) + ph
            restrictions[i][1] = min(h, mxh_before)
        print(restrictions)
        res = 0
        for i in range(len(restrictions)-1):
            x, h = restrictions[i]
            nx, nh = restrictions[i+1]
            gapx = nx - x
            gaph = nh - h
            # if i spend z going up => h + z, but only gapx - z left
            # so h + z - (gapx - z) <= nh, so h - gapx + 2z <= nh
            # so 2z <= gaph + gapx
            z = (gaph + gapx) // 2
            res = max(res, h + z)
        return res
        