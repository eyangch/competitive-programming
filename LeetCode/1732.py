class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        import numpy as np; return max(0, np.cumsum(gain).max().item())
