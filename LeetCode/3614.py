class Solution:
    def processStr(self, s: str, k: int) -> str:
        r_len = 0
        r_len_n = []
        for c in s:
            if c == '*':
                r_len = max(0, r_len-1)
            elif c == '#':
                r_len *= 2
            elif c == '%':
                pass
            else:
                r_len += 1
            r_len_n.append(r_len)
        if k >= r_len_n[-1]:
            return '.'
        for i, c in reversed(list(enumerate(s))):
            after_len = r_len_n[i]
            if c == '*':
                pass
            elif c == '#':
                assert after_len % 2 == 0
                if after_len != 0:
                    k %= after_len // 2
            elif c == '%':
                k = after_len - 1 - k
            else:
                if k == after_len - 1:
                    return c
        assert False
            
