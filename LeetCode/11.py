class Solution:
    def maxArea(self, height: List[int]) -> int:
        points = sorted(zip(range(len(height)), height), key=lambda x: x[1], reverse=True)
        ans = 0
        mm = [len(height), 0]
        for point in points:
            mm[0] = min(mm[0], point[0])
            mm[1] = max(mm[1], point[0])
            ans = max(ans, point[1] * max(point[0] - mm[0], mm[1] - point[0]))
        return ans

