class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        return sum(1 if pt in word else 0 for pt in patterns)