class Solution:
    def reverseParentheses(self, s: str) -> str:
        pmatch = [-1 for _ in s]
        rpmatch = [-1 for _ in s]
        stack = []
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            if s[i] == ')':
                z = stack.pop()
                pmatch[z] = i
        rs = s[::-1].replace('(', '!').replace(')', '(').replace('!', ')')
        stack = []
        for i in range(len(rs)):
            if rs[i] == '(':
                stack.append(i)
            if rs[i] == ')':
                z = stack.pop()
                rpmatch[z] = i
        #print(s)
        #print(rs)
        def solve(s: str, rs: str, pmatch: List[int], rpmatch: List[int], pos: int) -> List[str]:
            ret = []
            while pos < len(s) and s[pos] != ')':
                if s[pos] == '(':
                    pos = pmatch[pos]
                    ret += solve(rs, s, rpmatch, pmatch, len(s) - pos)
                else:
                    ret += s[pos]
                pos += 1
            return ret
        return "".join(solve(s, rs, pmatch, rpmatch, 0))

