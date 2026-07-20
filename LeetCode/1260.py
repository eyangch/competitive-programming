class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        import numpy as np
        return np.roll(np.array(grid), k).tolist()

