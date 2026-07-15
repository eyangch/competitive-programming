class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ret = []
        intervals.sort(key=lambda x: x[1])
        for interval in intervals:
            min_x = interval[0]
            while len(ret) > 0 and interval[0] <= ret[-1][1]:
                cur_x, _ = ret.pop()
                min_x = min(min_x, cur_x)
            ret.append([min_x, interval[1]])
        return ret