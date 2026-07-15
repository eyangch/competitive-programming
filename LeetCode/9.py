class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        rs = ''.join(reversed(s))
        return s == rs