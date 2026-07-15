class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        diff = [g - c for g, c in zip(gas, cost)] * 2
        i = 0
        while i < len(diff):
            j, s = i, 0
            while j < len(diff) and s >= 0:
                s += diff[j]
                j += 1
            if j - i > len(gas):
                return i
            i = j
        return -1