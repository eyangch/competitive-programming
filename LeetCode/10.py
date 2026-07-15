from functools import cache

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache
        def isMatchHelper(s, p, s_i, p_i):
            if s_i == len(s) and p_i == len(p):
                return True
            
            followed_by_star = p_i < len(p) - 1 and p[p_i+1] == '*'

            res = False
            if followed_by_star:
                res = isMatchHelper(s, p, s_i, p_i+2)

            if res:
                return True

            if s_i == len(s) or p_i == len(p):
                return False

            cc_match = p[p_i] == '.' or p[p_i] == s[s_i]

            if not followed_by_star:
                if cc_match:
                    return isMatchHelper(s, p, s_i+1, p_i+1)
                return False
            else:
                if cc_match:
                    res |= isMatchHelper(s, p, s_i+1, p_i)
                return res

        return isMatchHelper(s, p, 0, 0)
