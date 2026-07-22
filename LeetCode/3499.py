class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        zero_sections = []
        cur_zero_section = 0
        base = s.count('1')
        for c in s:
            if c == '0':
                cur_zero_section += 1
            if c == '1':
                if cur_zero_section > 0:
                    zero_sections.append(cur_zero_section)
                cur_zero_section = 0
        if cur_zero_section > 0:
            zero_sections.append(cur_zero_section)

        ps = [zero_sections[i] + zero_sections[i+1] for i in range(len(zero_sections)-1)]
        if len(ps) == 0:
            return base
        return base + max(ps)

