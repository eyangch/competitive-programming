class Solution:
    def doesAliceWin(self, s: str) -> bool:
        if len([i for i in "aeiou" if i in s]) > 0:
            return True
        return False