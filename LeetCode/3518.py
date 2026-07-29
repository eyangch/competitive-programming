class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        occ = [0] * 26
        occ2 = [0] * 26
        for c in s[:len(s)//2]:
            occ[ord(c)-ord('a')] += 1
        ncnk = 1
        ncnk_arr = []
        n = 0

        def solve():
            nonlocal ncnk
            nonlocal k
            nonlocal n
            ans = []
            for i in range(26):
                for j in range(occ[i]-occ2[i]):
                    ans.append(chr(i+ord('a')))
            # print(ans)
            # print(occ2)
            while sum(occ2) > 0:
                ahhhh = False
                for i in range(26):
                    if ahhhh:
                        break
                    if occ2[i] == 0:
                        continue
                    # if i bring the j-th i char up
                    ncnk_z = ncnk * occ2[i] // n
                    if k > ncnk_z:
                        # print(ncnk_z, k)
                        k -= ncnk_z
                    else:
                        # print(ncnk_z, k, "hehe")
                        n -= 1
                        ncnk = ncnk_z
                        ans.append(chr(i+ord('a')))
                        occ2[i] -= 1
                        ahhhh = True
            prelim = ''.join(ans)
            if len(s) % 2 == 1:
                return prelim + s[len(s) // 2] + ''.join(reversed(prelim))
            else:
                return prelim + ''.join(reversed(prelim))

        if ncnk >= k:
            return solve()

        for i in range(25, -1, -1):
            for j in range(occ[i]):
                n += 1
                ncnk = ncnk * n // (j+1)
                occ2[i] += 1
                ncnk_arr.append(ncnk)

                if ncnk >= k:
                    return solve()
        return ""
 
