class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        times = []
        for pt in timePoints:
            hr, mn = map(int, pt.split(':'))
            cur = hr * 60 + mn
            times.extend([cur, cur + 24 * 60])
        
        times.sort()

        mn_diff = 1e9
        for i in range(len(times)-1):
            mn_diff = min(mn_diff, times[i+1] - times[i])
        
        return mn_diff