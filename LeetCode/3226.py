class Solution:
    def minChanges(self, n: int, k: int) -> int:
        if (n & k) == k:
            return (n ^ k).bit_count()
        return -1